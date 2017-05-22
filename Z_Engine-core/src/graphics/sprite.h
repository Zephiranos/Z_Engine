#pragma once

#include "renderable2d.h"
//////////////////////
// sprite class header
//////////////////////

namespace z_engine {
	namespace graphics {

		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, const maths::vec4& color);

		};
	}
}