#include "vec4.h"

///////////////////////////
// 4D vector implementation
///////////////////////////

namespace z_engine {
	namespace maths {

		//Constructors
		vec4::vec4():
			x(0),
			y(0),
			z(0),
			w(0)
		{
		}

		vec4::vec4(const float& newx, const float& newy, const float& newz, const float& neww):
			x(newx),
			y(newy),
			z(newz),
			w(neww)
		{
		}

		//Math functions
		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::substract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		//Operators
#pragma region Operators

		vec4& operator+(vec4 lhs, const vec4& rhs)
		{
			return lhs.add(rhs);
		}

		vec4& operator-(vec4 lhs, const vec4& rhs)
		{
			return lhs.substract(rhs);
		}

		vec4& operator*(vec4 lhs, const vec4& rhs)
		{
			return lhs.multiply(rhs);
		}

		vec4& operator/(vec4 lhs, const vec4& rhs)
		{
			return lhs.divide(rhs);
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}

		vec4& vec4::operator-=(const vec4& other)
		{
			return substract(other);
		}

		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}

		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool vec4::operator!=(const vec4& other)
		{
			return !(x == other.x && y == other.y && z == other.z && w == other.w);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}

#pragma endregion
}	}