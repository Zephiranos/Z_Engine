#include "vec3.h"

///////////////////////////
// 3D vector implementation
///////////////////////////

namespace z_engine {
	namespace maths {

		//Constructors
		vec3::vec3():
			x(0),
			y(0),
			z(0)
		{
		}

		vec3::vec3(const float& newx, const float& newy, const float& newz):
			x(newx),
			y(newy),
			z(newz)
		{
		}

		//Math functions
		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::substract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		//Operators
#pragma region Operators
		vec3& operator+(vec3 lhs, const vec3& rhs)
		{
			return lhs.add(rhs);
		}

		vec3& operator-(vec3 lhs, const vec3& rhs)
		{
			return lhs.substract(rhs);
		}

		vec3& operator*(vec3 lhs, const vec3& rhs)
		{
			return lhs.multiply(rhs);
		}

		vec3& operator/(vec3 lhs, const vec3& rhs)
		{
			return lhs.divide(rhs);
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			return substract(other);
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}

		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator!=(const vec3& other)
		{
			return !(x == other.x && y == other.y && z == other.z);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

#pragma endregion

}	}