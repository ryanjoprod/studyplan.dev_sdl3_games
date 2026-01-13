#pragma once
#include <SDL3/SDL.h>

#include <iostream>

class Window {
public:
  Window() {
    window = SDL_CreateWindow(
      "Hello Window",
      getWidth(), getHeight(),
      SDL_WINDOW_RESIZABLE
    );
  }

  int getWidth() const { return 800; }
  int getHeight() const { return 300; }

  void render() {
    const auto* fmt{SDL_GetPixelFormatDetails(
      GetSurface()->format
    )};

    SDL_FillSurfaceRect(
      GetSurface(),
      nullptr,
      SDL_MapRGB(fmt, nullptr, 50, 50, 50)
    );
  }

  void update() {
    SDL_UpdateWindowSurface(window);
  }

  SDL_Surface* GetSurface() const {
    return SDL_GetWindowSurface(window);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  ~Window() {
    if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
      SDL_DestroyWindow(window);
    }
  }

private:
  SDL_Window* window{nullptr};
};
