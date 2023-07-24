#include <game/errors/SDL_error_handler.hpp>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

void Game::Exit_with_error(){
    std::cerr << "Erreur SDL: " << SDL_GetError() << std::endl;
    SDL_Quit();
    exit(EXIT_FAILURE);
}