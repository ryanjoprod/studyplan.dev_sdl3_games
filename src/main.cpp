#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  Window gameWindow;

  bool isRunning = true;
  SDL_Event event;
  while(isRunning) {
    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }

    gameWindow.render();

    // Render everything else

    gameWindow.update();
  }

  SDL_Quit();

  return 0;
}
