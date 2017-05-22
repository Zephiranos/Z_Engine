#pragma once

#include <iostream>

/////////////////////////
// 2D vector class header
/////////////////////////

namespace z_engine {
	namespace maths {

		struct vec2
		{
			float x, y;
			vec2();
			vec2(const float& x, const float& y);

// math
			vec2& add(const vec2& other);
			vec2& substract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

// operators
			friend vec2& operator+(vec2 lhs, const vec2& rhs);
			friend vec2& operator-(vec2 lhs, const vec2& rhs);
			friend vec2& operator*(vec2 lhs, const vec2& rhs);
			friend vec2& operator/(vec2 lhs, const vec2& rhs);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};

} }