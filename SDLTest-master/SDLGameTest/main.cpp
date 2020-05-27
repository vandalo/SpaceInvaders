#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

#include <stdlib.h>
#include "Application.h"
#include "Globals.h"
#include <iostream>

enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;

int main(int, char **) {
 /* if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window *win =
      SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == nullptr) {
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Surface *space_ship_surface = IMG_Load("Assets/Player/spaceship.png");
  if (!space_ship_surface) {
    std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
    return 0;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, space_ship_surface);
  if (!texture) {
    std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << std::endl;
    return 0;
  }

  SDL_Event e;
  bool running = true;
  while (running) {
    SDL_PollEvent(&e);
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        break;
      case SDL_KEYDOWN:
        break;
      case SDL_USEREVENT:
        break;
      default:
        break;
    }

    SDL_Rect texture_rect;
    texture_rect.x = 0;   // the x coordinate
    texture_rect.y = 0;   // the y coordinate
    texture_rect.w = 64;  // the width of the texture
    texture_rect.h = 64;  // the height of the texture

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, &texture_rect);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(space_ship_surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;*/
	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;

	while (state != MAIN_EXIT)
	{
		switch (state)
		{
		case MAIN_CREATION:

			LOG("Application Creation --------------");
			App = new Application();
			state = MAIN_START;
			break;

		case MAIN_START:

			LOG("Application Init --------------");
			if (App->Init() == false)
			{
				LOG("Application Init exits with error -----");
				state = MAIN_EXIT;
			}
			else
			{
				state = MAIN_UPDATE;
				LOG("Application Update --------------");
			}

			break;

		case MAIN_UPDATE:
		{
			int update_return = App->Update();

			if (update_return == UPDATE_ERROR)
			{
				LOG("Application Update exits with error -----");
				state = MAIN_EXIT;
			}

			if (update_return == UPDATE_STOP)
				state = MAIN_FINISH;
		}
		break;

		case MAIN_FINISH:

			LOG("Application CleanUp --------------");
			if (App->CleanUp() == false)
			{
				LOG("Application CleanUp exits with error -----");
			}
			else
				main_return = EXIT_SUCCESS;

			state = MAIN_EXIT;

			break;

		}
	}

	RELEASE(App);
	LOG("Bye :)\n");
	return main_return;
}
