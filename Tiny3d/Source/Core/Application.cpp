
#include <3ds.h>  // Required for 3DS entry point and hardware
#include "Application.h"

namespace Tiny3d {

    Application::Application(const ApplicationSpecification& specification) : m_Specification(specification) {
        gfxInitDefault();
        consoleInit(GFX_TOP, NULL);
    }

    Application::~Application() {
        // Clean up resources
    }

    void Application::Run() {
        m_Running = true;
        while (m_Running && aptMainLoop()) {
            for (const std::unique_ptr<Layer>& layer : m_LayerStack) {
                layer->OnUpdate(0.f);  // TODO: proper timestep
            }

            for (const std::unique_ptr<Layer>& layer : m_LayerStack) {
                layer->OnRender();
            }

            // Flush and swap framebuffers
            gfxFlushBuffers();
            gfxSwapBuffers();
            gspWaitForVBlank();
        }
    }

    void Application::Stop() {
        gfxExit();
    }

    void Application::OnEvent(Event& event) {
        // Handle events (e.g., input, window events, etc.)
    }

}