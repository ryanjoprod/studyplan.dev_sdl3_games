#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  Window GameWindow;

  bool IsRunning = true;
  SDL_Event Event;
  while(IsRunning) {
    while(SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }

    // SDL_SetRenderDrawColor(GameWindow.renderer, 255, 255, 255, 255);
    // SDL_RenderClear(GameWindow.renderer);
    // SDL_RenderPresent(GameWindow.renderer);
  }

  SDL_Quit();

  return 0;
}
