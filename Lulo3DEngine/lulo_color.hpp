#pragma once
#include <cstdint>

namespace lulo
{
	class Color
	{
	public:
		float r, g, b, a;

		Color(const float r = 1.0f, const float g = 1.0f, const float b = 1.0f, const float a = 1.0f);

		uint32_t to_uint32() const;

		// redefine operators
		Color operator + (const Color&) const;
		Color operator - (const Color&) const;
		Color operator * (const float) const;
	};
}
