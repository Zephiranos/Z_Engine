#pragma once

#include <GL\glew.h>
#include "renderable2d.h"
#include "../maths/maths.h"

//////////////////////
// Renderer class header
//////////////////////

namespace z_engine {
	namespace graphics {

		class Renderer2D
		{
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};

	}
}
