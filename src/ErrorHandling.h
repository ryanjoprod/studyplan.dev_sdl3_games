#pragma once

#include <SDL3/SDL.h>

#include <iostream>
#include <string>

// Define me to enable error logging:
#define ERROR_LOGGING

void CheckSDLError(const std::string& action) {
#ifdef ERROR_LOGGING
  const char* error{SDL_GetError()};
  if (*error != '\0') {
    std::cout << action << " Error: " << error << '\n';
    SDL_ClearError();
  }
#endif
}
