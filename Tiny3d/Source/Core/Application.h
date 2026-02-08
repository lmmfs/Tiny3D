#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Event/Event.h"
#include "Layer.h"

 namespace Tiny3d {

    struct ApplicationSpecification {
		std::string Name = "Application";
		//WindowSpecification WindowSpec;
	};
 
    class Application {
        public:
        Application(const ApplicationSpecification& specification = ApplicationSpecification());
		~Application();

		void Run();
		void Stop();
		void OnEvent(Event& event);

        template<typename TLayer>
		void PushLayer()
		{
			m_LayerStack.push_back(std::make_unique<TLayer>());
		}

        private:
        ApplicationSpecification m_Specification;
		bool m_Running = false;
		//std::shared_ptr<Window> m_Window;

        std::vector<std::unique_ptr<Layer>> m_LayerStack;
    };


}
