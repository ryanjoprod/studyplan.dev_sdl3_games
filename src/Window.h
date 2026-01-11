#pragma once
#include <SDL3/SDL.h>

#include <iostream>

class Window {
public:
  // SDL_Renderer* renderer{nullptr};

  Window() {
    window = SDL_CreateWindow(
      "Hello Window",
      800, 300,
      SDL_WINDOW_RESIZABLE
    );

    const auto* fmt{SDL_GetPixelFormatDetails(
      GetSurface()->format
    )};

    SDL_FillSurfaceRect(
      GetSurface(),
      nullptr,
      SDL_MapRGB(fmt, nullptr, 50, 50, 50)
    );

    SDL_UpdateWindowSurface(window);
  }

  SDL_Surface* GetSurface() const {
    return SDL_GetWindowSurface(window);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  ~Window() {
    if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
      // SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
    } else {
      std::cout << "Skipping SDL_DestroyWindow\n";
    }
  }

private:
  SDL_Window* window{nullptr};
};
