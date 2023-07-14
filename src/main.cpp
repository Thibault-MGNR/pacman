#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <game/game.hpp>
#include <game/map/map.hpp>
#include <string>

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    Game::Window_parameter window_param;
    window_param.title = "Pac-man";
    window_param.size = {700, 1000};
    window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};

    Game::Window window{window_param};

    Game::Renderer renderer{window};

    Game::Texture texture{std::make_shared<Game::Renderer>(renderer), "data/spritesheet.png"};

    Game::Map map{std::make_shared<Game::Renderer>(renderer)};

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer.get_renderer_ptr());
        map.draw();
        SDL_RenderPresent(renderer.get_renderer_ptr());
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}