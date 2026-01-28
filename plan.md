# Plan: Move 3DS Initialization and Main Loop into Tiny3d `Application`

TL;DR
--
Move platform-specific 3DS lifecycle (initialization, main loop, and shutdown)
into the `Tiny3d::Application` class so the engine owns platform startup and
control flow. Keep platform headers out of the public header by implementing
3DS specifics in the .cpp guarded with `#ifdef __3DS__`.

Steps
--
1. Add API to `Tiny3d/Source/Core/Application.h`:
   - `bool Init(int argc, char** argv);`
   - `void Run();` (blocks and owns main loop)
   - `void Shutdown();`
   - `void RequestExit();`
   - `virtual void Update(float dt);` (override hook)
   - `virtual void Render();` (override hook)

2. Implement lifecycle and 3DS details in `Tiny3d/Source/Core/Application.cpp`:
   - Include `<3ds.h>` only inside `#ifdef __3DS__`.
   - Move `gfxInitDefault()` and `consoleInit()` into `Init()`.
   - Implement `Run()` to use `aptMainLoop()` with `hidScanInput()`/
     `hidKeysDown()`, call `Update()`/`Render()`, then `gfxFlushBuffers()`,
     `gfxSwapBuffers()`, `gspWaitForVBlank()`.
   - Call `gfxExit()` in `Shutdown()`.

3. Update `Sandbox/Source/Main.cpp` to use the new API:
   - Create `Tiny3d::Application app;`.
   - Call `if (!app.Init(argc, argv)) return 1;` then `app.Run();` and
     `app.Shutdown();`.
   - Remove direct calls to `gfxInitDefault()`, `aptMainLoop()` loop and
     `gfxExit()` from `Main.cpp`.

4. Build adjustments and safeguards:
   - Keep `<3ds.h>` out of `Application.h` to preserve portability.
   - Ensure Makefiles compile/link files referencing `<3ds.h>` with the
     correct 3DS toolchain flags and that `__3DS__` is defined.
   - Review global/static initialization order so no code requires graphics
     before `Init()` runs.

5. Testing
   - Build the sandbox and verify the app starts, that `Update()`/`Render()`
     run, and pressing START exits.
   - If desired, offer an alternative non-blocking API: `Poll()` + caller
     loop (for more control).

Recommended Minimal `Application` Behavior
--
- `Init()` — prepare engine and platform subsystems (returns success/fail).
- `Run()` — block and drive the main loop until `RequestExit()` or platform
  signals exit.
- `Shutdown()` — release platform resources.

Files to change (suggested)
--
- `Tiny3d/Source/Core/Application.h` — add declarations and docs.
- `Tiny3d/Source/Core/Application.cpp` — implement lifecycle; add
  `#ifdef __3DS__` implementations using `<3ds.h>`.
- `Sandbox/Source/Main.cpp` — construct and run `Tiny3d::Application`.

Next steps I can take for you
--
- Draft `Application.h` and `Application.cpp` with a guarded 3DS
  implementation and apply the `Main.cpp` change.
- Or just produce unified diffs / a patch for you to review.

If you want me to implement the code and apply the edits now, tell me and
I'll proceed with the concrete patch.
