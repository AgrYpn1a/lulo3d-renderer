#pragma once
#include <cstdint>

namespace lulo
{
	class Test
	{

	};

	class Vertex
	{
	private:
		uint16_t x, y;
	public:
		Vertex(const uint16_t, const uint16_t);
		
		// setters
		void set_buffer(uint32_t const*);

		// getters
		const uint16_t get_x() const;
		const uint16_t get_y() const;

		// If A is current vertex, returns length of vector OA, where 
		// O is (0, 0)
		double length() const;

		double distance(const Vertex& v) const;

		// basic operations
		Vertex operator-(const Vertex& v) const;
		Vertex operator+(const Vertex& v) const;
		Vertex operator*(const float a) const;
		double operator*(const Vertex& v) const;

		// static methods
		static bool collinear(Vertex&, Vertex&, Vertex&);
	};

	class Line
	{
	private:
		const Vertex v_start, v_end;
	public:
		Line(Vertex v_start, Vertex v_end);
		Line(uint16_t v_start_x, uint16_t v_start_y, uint16_t v_end_x, uint16_t v_end_y);
		~Line();
	};

	class Polygon
	{

	};
}