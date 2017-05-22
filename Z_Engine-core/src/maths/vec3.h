#pragma once

#include <iostream>

/////////////////////////
// 3D vector class header
/////////////////////////

namespace z_engine {
	namespace maths {

		struct vec3
		{
			float x, y, z;
			vec3();
			vec3(const float& x, const float& y, const float& z);

			// math
			vec3& add(const vec3& other);
			vec3& substract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			// operators
			friend vec3& operator+(vec3 lhs, const vec3& rhs);
			friend vec3& operator-(vec3 lhs, const vec3& rhs);
			friend vec3& operator*(vec3 lhs, const vec3& rhs);
			friend vec3& operator/(vec3 lhs, const vec3& rhs);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};

} }