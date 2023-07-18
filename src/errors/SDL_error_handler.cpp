#include <game/errors/SDL_error_handler.hpp>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace Game{
    void check_sdl_error(){
        std::string sdlError{SDL_GetError()};

        if (sdlError != "\0") {
            std::cerr << "SDL Error: " << sdlError << std::endl;
            SDL_ClearError();
        }
    }
}