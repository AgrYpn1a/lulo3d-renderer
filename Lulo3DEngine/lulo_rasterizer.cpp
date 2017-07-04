#include "lulo_rasterizer.hpp"

#include <cmath>
#include <memory>

namespace lulo
{

	// register local functions
	static void draw_line_east(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1);
	static void draw_line_south(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1);
	static void draw_line_north(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1);
	static inline void swap(uint16_t* a, uint16_t* b);

	Rasterizer::Rasterizer(const Window* const _win) : 
		window(_win), 
		color(Color(1, 0, 0, 1)), 
		buffer(_win->get_buffer()) { }

	void Rasterizer::mark_pixel(const uint16_t& x, const uint16_t& y) const
	{
		this->buffer[(this->window->get_width() * y) + x] = color.to_uint32();
	}

	void Rasterizer::draw_pixel(const uint16_t& x, const uint16_t& y) const
	{
		this->buffer[(this->window->get_width() * y) + x] = color.to_uint32();
		// this->window->render();
	}

	void Rasterizer::draw_line(const Vertex& p, const Vertex& q) const
	{
		// we draw line from (x0, y0) to (x1, y1)
		uint16_t x0 = p.get_x(), y0 = p.get_y();
		uint16_t x1 = q.get_x(), y1 = q.get_y();

		bool swapped = false;

		if (x0 > x1)
		{
			swap(&x0, &x1);
			swap(&y0, &y1);
			swapped = true;
		}

		// calculate distances between points
		const uint16_t dx = x1 - x0;
		const uint16_t dy = abs(y1 - y0);

		if (dx > dy)
			draw_line_east(this, x0, y0, x1, y1);
		else if (y1 > y0)
			draw_line_north(this, x0, y0, x1, y1);
		else
			draw_line_south(this, x0, y0, x1, y1);

		if (swapped)
		{
			swap(&x0, &x1);
			swap(&y0, &y1);
		}

	}

	void Rasterizer::draw_point(const Vertex& v) const
	{
		draw_line(v, v);
	}

	static void draw_line_east(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1)
	{
		// set step
		uint8_t step_y = 1;
		if (y1 < y0) step_y = -1;

		uint16_t dx = x1 - x0;
		uint16_t dy = abs(y1 - y0);

		uint8_t lambda = 2 * dy - dx;
		uint8_t incr_1 = 2 * dy;
		uint8_t incr_2 = 2 * (dy - dx);

		while (x0 < x1)
		{
			x0++;
			if (lambda < 0)
				lambda += incr_1;
			else
			{
				lambda += incr_2;
				y0 += step_y;
			}

			raster->draw_pixel(x0, y0);
		}
	}

	static void draw_line_south(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1)
	{
		uint16_t dx = x1 - x0;
		uint16_t dy = abs(y1 - y0);

		uint8_t lambda = 2 * dx - dy;
		uint8_t incr_1 = 2 * dx;
		uint8_t incr_2 = 2 * (dx - dy);

		while (y0 > y1)
		{
			y0--;
			if (lambda < 0)
				lambda += incr_1;
			else
			{
				lambda += incr_2;
				x0++;
			}

			raster->draw_pixel(x0, y0);
		}
	}

	static void draw_line_north(const Rasterizer* const raster, uint16_t x0, uint16_t y0, const uint16_t x1, const uint16_t y1)
	{
		uint16_t dx = x1 - x0;
		uint16_t dy = abs(y1 - y0);

		uint8_t lambda = 2 * dx - dy;
		uint8_t incr_1 = 2 * dx;
		uint8_t incr_2 = 2 * (dx - dy);

		while (y0 < y1)
		{
			y0++;
			if (lambda < 0)
				lambda += incr_1;
			else
			{
				lambda += incr_2;
				x0++;
			}

			raster->draw_pixel(x0, y0);
		}
	}

	static inline void swap(uint16_t* a, uint16_t* b)
	{
		uint16_t tmp = *a;
		*a = *b;
		*b = tmp;
	}

}