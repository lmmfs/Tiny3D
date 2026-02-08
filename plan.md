# Plan: Add Window Class for 3DS Screen Management

**TL;DR**: Create a `Window` class in `Tiny3d/Source/Core/Window.h` and `Window.cpp` that abstracts 3DS graphics initialization, buffer management, and screen swaps. The `Application` class will own and manage the `Window` lifecycle. A `WindowSpecification` struct will provide configuration options. This decouples graphics lifecycle from the main application loop and establishes a clean separation for future Renderer integration.

## Steps

### 1. Create WindowSpecification struct
**File**: `Tiny3d/Source/Core/Window.h`

Define configuration struct following `ApplicationSpecification` pattern:
- Include properties for screen layout, resolution hints (if configurable on 3DS)
- Document 3DS-specific limitations (e.g., fixed dual-screen layout, 240×320×2)

### 2. Create Window class
**File**: `Tiny3d/Source/Core/Window.h`

Class definition with:
- Constructor: `Window(const WindowSpecification& spec)`
  - Call `gfxInitDefault()` to initialize graphics
  - Call `consoleInit()` for optional debug console
  - Store specification for later reference
- Destructor: Call `gfxExit()` to cleanup graphics
- Public methods:
  - `void BeginFrame()` - calls `gfxFlushBuffers()`
  - `void EndFrame()` - calls `gfxSwapBuffers()` and `gspWaitForVBlank()`
  - `void OnUpdate(float timestep)` - optional window-level updates
  - `const WindowSpecification& GetSpecification() const` - getter for spec
- Private members: `m_Specification`

### 3. Implement Window class
**File**: `Tiny3d/Source/Core/Window.cpp`

Implementation with:
- Include `<3ds.h>` and other libctru dependencies
- Implement lifecycle management with proper error handling where applicable

### 4. Update Application class header
**File**: `Tiny3d/Source/Core/Application.h`

Changes:
- Uncomment and fix the `WindowSpecification` reference (currently line ~6)
- Uncomment `std::shared_ptr<Window> m_Window;` or change to `std::unique_ptr<Window>`
- Update constructor to accept `ApplicationSpecification` with window config
- Add `#include "Window.h"`

### 5. Update Application implementation
**File**: `Tiny3d/Source/Core/Application.cpp`

Changes:
- Move `gfxInitDefault()` call from constructor to Window initialization (or Window construction)
- Update `Run()` loop:
  - Replace direct `gfxFlushBuffers()` call with `m_Window->BeginFrame()`
  - Replace `gfxSwapBuffers()` and `gspWaitForVBlank()` calls with `m_Window->EndFrame()`
  - Keep layer update/render calls in between

### 6. Update Sandbox Main (optional)
**File**: `Sandbox/Source/Main.cpp`

- No changes needed if using default ApplicationSpecification
- Or add optional WindowSpecification to ApplicationSpecification if desired

### 7. Update Tiny.h public API
**File**: `Tiny3d/Tiny.h`

- Add `#include "Core/Window.h"` to public API if applicable (following current pattern with Layer.h, etc.)

## Design Decisions

| Decision | Choice | Rationale |
|----------|--------|-----------|
| **Window ownership** | `Application` owns `Window` as `std::shared_ptr<Window>` | Matches commented intent in existing Application.h code |
| **Responsibilities** | Window handles buffer/display management only | Future Renderer class will handle graphics objects; clean separation of concerns |
| **Lifecycle** | Window init ties directly to Application init | No lazy initialization; simpler lifecycle management |
| **Naming** | Follows existing conventions PascalCase, m_ prefix, Tiny3d namespace | Consistency with codebase |
| **Input handling** | Keep in layer system for now | Renderer gets priority; input can be centralized later if needed |

## Verification Checklist

- [ ] Compile: `make` in Tiny3d/ and Sandbox/ directories succeeds without errors
- [ ] Functional: Sandbox.3dsx runs with same visual output (dual screens visible, debug console active)
- [ ] Verify gfx initialization happens during Application construction
- [ ] Verify gfx cleanup happens on Application destruction
- [ ] Verify vsync timing remains consistent (no frame pacing changes)
- [ ] No regressions in MainLayer rendering

## Files to Modify/Create

| File | Action | Notes |
|------|--------|-------|
| `Tiny3d/Source/Core/Window.h` | Create | Header with WindowSpecification struct and Window class |
| `Tiny3d/Source/Core/Window.cpp` | Create | Implementation of Window lifecycle |
| `Tiny3d/Source/Core/Application.h` | Modify | Add Window member, uncomment Window references |
| `Tiny3d/Source/Core/Application.cpp` | Modify | Move gfx calls to Window, update Run() loop |
| `Tiny3d/Tiny.h` | Modify | Add Window.h to public API |
| `Sandbox/Source/Main.cpp` | Optional | No changes needed for basic functionality |
