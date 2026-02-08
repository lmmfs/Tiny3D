#include <3ds.h>   // Required for 3DS entry point and hardware
#include "MainLayer.h"
#include "Tiny.h"


int main(int argc, char* argv[]) {
    // Create application specification
    Tiny3d::ApplicationSpecification app_spec;
    app_spec.Name = "Tiny3D Sandbox";
    
    // Create the application
    Tiny3d::Application app(app_spec);
    
    // Add the main layer
    app.PushLayer<MainLayer>();
    
    // Run the application
    app.Run();
    
    // Stop the application (cleanup)
    app.Stop();
    
    return 0;
}
