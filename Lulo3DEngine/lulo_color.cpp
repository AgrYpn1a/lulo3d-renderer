#include "lulo_color.hpp"

namespace lulo
{
	Color::Color(float r, const float g, const float b, const float a) : 
		r(r), g(g), b(b), a(a)
	{ }

	uint32_t Color::to_uint32() const
	{
		uint32_t r = static_cast<uint32_t>(this->r * 255);
		uint32_t g = static_cast<uint32_t>(this->g * 255);
		uint32_t b = static_cast<uint32_t>(this->b * 255);
		uint32_t a = static_cast<uint32_t>(this->a * 255);

		return (a << 24) | (r << 16) || (g << 8) | b;
	}

	// redefine operators
	Color Color::operator + (const Color& c) const
	{
		return Color(this->r + c.r, this->g + c.g, this->b + c.b, this->a + c.a);
	}

	Color Color::operator - (const Color& c) const
	{
		return Color(this->r - c.r, this->g - c.g, this->b - c.b, this->a - c.a);
	}

	Color Color::operator * (const float f) const
	{
		return Color(this->r * f, this->g * f, this->b * f, this->a * f);
	}
}