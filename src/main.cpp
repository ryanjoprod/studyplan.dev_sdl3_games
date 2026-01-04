#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* window;
  SDL_Renderer* renderer;

  SDL_CreateWindowAndRenderer(
    "Hello World!", 800, 300, 0, &window, &renderer
  );


  bool IsRunning = true;
  SDL_Event Event;
  while(IsRunning) {
    while(SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
