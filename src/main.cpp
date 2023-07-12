#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <game/game.hpp>

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    Game::Window_parameter window_param;
    window_param.title = "Pac-man";
    window_param.size = {640, 480};
    window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};

    Game::Window window{window_param};

    Game::Renderer renderer{window};
    
    Game::Texture texture{renderer, "data/spritesheet.png"};

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer.get_renderer().get());
        SDL_RenderCopy(renderer.get_renderer().get(), texture.get_texture().get(), NULL, NULL);
        SDL_RenderPresent(renderer.get_renderer().get());
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}