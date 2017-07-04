#include "lulo_2d_geometry.hpp"
#include <cmath>

namespace lulo
{

#pragma region Vertex

	Vertex::Vertex(const uint16_t, const uint16_t)
	{

	}

	// setters
	void Vertex::set_buffer(uint32_t const*)
	{

	}

	// getters
	const uint16_t Vertex::get_x() const
	{
		return this->x;
	}

	const uint16_t Vertex::get_y() const
	{
		return this->y;
	}

	// If A is current vertex, returns length of vector OA, where 
	// O is (0, 0)
	double Vertex::length() const
	{
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}

	double Vertex::distance(const Vertex& v) const
	{
		return sqrt(pow(this->x - v.x, 2) + pow(this->y - v.y, 2));
	}

	// basic operations
	Vertex Vertex::operator-(const Vertex& v) const
	{
		return Vertex(this->x - v.x, this->y - v.y);
	}

	Vertex Vertex::operator+(const Vertex& v) const
	{
		return Vertex(this->x + v.x, this->y + v.y);
	}
	
	double Vertex::operator*(const Vertex& v) const
	{
		return this->x * v.x, this->y * v.y;
	}

	Vertex Vertex::operator*(const float a) const
	{
		return Vertex(static_cast<int>(this->x * a), static_cast<int>(this->y * a));
	}


	// static methods
	bool Vertex::collinear(Vertex&, Vertex&, Vertex&)
	{
		// TODO implement Vertex::collinear
		return false;
	}
#pragma endregion

#pragma region Line

#pragma endregion

#pragma region Polygon

#pragma endregion

}