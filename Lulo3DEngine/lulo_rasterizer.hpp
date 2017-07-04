#pragma once
#include <cstdint>

#include "lulo_color.hpp"
#include "lulo_window.hpp"
#include "lulo_2d_geometry.hpp"

namespace lulo
{
	class Rasterizer
	{
	private:
		uint32_t* const buffer = nullptr;
		const Window* const window = nullptr;
		lulo::Color color = NULL;
	public:
		Rasterizer(const Window* const);

		// Marks the pixel on screen, but does not render it. Rendering
		// should be done manually after.
		void mark_pixel(const uint16_t&, const uint16_t&) const;
		// Renders pixel on screen
		void draw_pixel(const uint16_t&, const uint16_t&) const;


		void draw_line(const Vertex&, const Vertex&) const;
		void draw_point(const Vertex&) const;
	};
}
