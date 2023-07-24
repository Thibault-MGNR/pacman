#include <iostream>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <game/game.hpp>
#include <game/map/map.hpp>
#include <game/events/events_pool.hpp>
#include <game/errors/SDL_error_handler.hpp>

int main(){
    Game::Game game;
    game.run();

    return EXIT_SUCCESS;
}