// This is not being used for the current projects
// but will need to be looked into later
#pragma once
#include <SDL3/SDL.h>

#include <memory>

// Define a customer deleter for SDL_Window*
struct SDLWindowDeleter {
  void operator()(SDL_Window* Ptr) const {
    if (Ptr && SDL_WasInit(SDL_INIT_VIDEO)) {
      SDL_DestroyWindow(Ptr);
    }
  }
};

// Alias for convenience
using UniqueSDLWindow = std::unique_ptr<
  SDL_Window, SDLWindowDeleter
>;

class Window {
public:
  Window() {
    // Get the raw pointer
    SDL_Window* Ptr{SDL_CreateWindow(
      "Smart Pointer Window",
      800, 300, 0
    )};

    // Store in the smart pointer
    SDLWindow = UniqueSDLWindow(Ptr);
  }

  // We still need a way to get the raw pointer
  // for interactions with other SDL functions
  SDL_Window* GetRaw() const {
    return SDLWindow.get();
  }

private:
  // Store the window resource in a unique_ptr
  UniqueSDLWindow SDLWindow{nullptr};
};
