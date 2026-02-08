#pragma once

#include "Event/Event.h"

namespace Tiny3d {

	class Layer {
	public:
		virtual ~Layer() = default;

		virtual void OnEvent(Event& event) {}

		virtual void OnUpdate(float ts) {}
		virtual void OnRender() {}
	};

}