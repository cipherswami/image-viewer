/**************************************************************
 * Author        : Aravind Potluri <aravindswami135@gmail.com>
 * Description   : Image Viewer with SDL2.
 ***************************************************************/

#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow(
      "SDL2 Window",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      800,
      600,
      SDL_WINDOW_SHOWN);

  if (!win)
  {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  int running = 1;
  SDL_Event e;

  while (running)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        running = 0;
      }
    }

    SDL_Delay(16); // ~60 FPS idle loop
  }

  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
