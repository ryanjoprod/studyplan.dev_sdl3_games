#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"
#include "ErrorHandling.h"

int main(int, char**) {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    std::cout << "Init failed: " << SDL_GetError();
  }

  Window gameWindow;

  bool isRunning = true;
  SDL_Event event;
  while(isRunning) {
    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }
  }

  SDL_Quit();

  return 0;
}
