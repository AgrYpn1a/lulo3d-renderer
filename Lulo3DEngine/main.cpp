// std::
#include <iostream>

// SDL
#include <SDL.h>

// project local
#include "lulo_window.hpp"

int main()
{
	lulo::Window window(800, 600);
	window.init();

	while (window.process())
	{
		SDL_Delay(100);
	}

	return 0;
}