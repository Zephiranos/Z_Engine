#include "vec2.h"

///////////////////////////
// 2D vector implementation
///////////////////////////

namespace z_engine {
	namespace maths {

//Constructors
		vec2::vec2():
			x(0),
			y(0)
		{
		}

		vec2::vec2(const float& newx, const float& newy):
			x(newx),
			y(newy)
		{
		}

//Math functions

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& vec2::substract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

//Operators
#pragma region Operators

		vec2& operator+(vec2 lhs, const vec2& rhs)
		{
			return lhs.add(rhs);
		}

		vec2& operator-(vec2 lhs, const vec2& rhs)
		{
			return lhs.substract(rhs);
		}

		vec2& operator*(vec2 lhs, const vec2& rhs)
		{
			return lhs.multiply(rhs);
		}

		vec2& operator/(vec2 lhs, const vec2& rhs)
		{
			return lhs.divide(rhs);
		}

		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);
		}

		vec2& vec2::operator-=(const vec2& other)
		{
			return substract(other);
		}

		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}

		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}

		bool vec2::operator==(const vec2& other)
		{
			return x == other.x && y == other.y;
		}

		bool vec2::operator!=(const vec2& other)
		{
			return !(x == other.x && y == other.y);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

#pragma endregion

		
}	}