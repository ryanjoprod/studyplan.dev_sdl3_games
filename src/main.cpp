#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"

void handleMotionEvent(SDL_MouseMotionEvent& e, Window& gameWindow) {
  std::cout << "Mouse Motion Detected - "
    << "x: " << e.x
    << ", y: " << e.y;

  std::cout << "\n Distance from Right: "
    << (float)gameWindow.getWidth() - e.x;

  std::cout << "\n Distance from Bottom: "
    << (float)gameWindow.getHeight() - e.y << '\n';
}

void handleButtonEvent(SDL_MouseButtonEvent& e) {
  if (e.button == SDL_BUTTON_RIGHT) {
    std::cout << "Right click or release\n";
  }

  if (e.button == SDL_BUTTON_LEFT &&
      e.down &&
      e.clicks > 2
  ) {
    std::cout << "Left double click\n";
  }
}

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  Window gameWindow;

  bool isRunning = true;
  SDL_Event e;
  while(isRunning) {
    while(SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_MOUSE_MOTION) {
        handleMotionEvent(e.motion, gameWindow);
      } else if (e.type == SDL_EVENT_WINDOW_MOUSE_ENTER) {
        std::cout << "Mouse Entered Window\n";
      } else if (e.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
        std::cout << "Mouse Left Window\n";
      } else if (
        e.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
        e.type == SDL_EVENT_MOUSE_BUTTON_UP
      ) {
        handleButtonEvent(e.button);
      } else if (e.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }

    gameWindow.render();
    gameWindow.update();
  }

  SDL_Quit();

  return 0;
}
