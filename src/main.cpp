#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <game/game.hpp>

SDL_Window* initDefaultWindow(){
    return SDL_CreateWindow("Affichage d'une image avec SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
}

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    auto create_window = [](){ // définition d'une fonction lambda
        return SDL_CreateWindow("Affichage d'une image avec SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    };

    std::shared_ptr<SDL_Window> window{create_window(), SDL_DestroyWindow};

    std::shared_ptr<SDL_Renderer> renderer{SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer};

    std::shared_ptr<SDL_Surface> imageSurface{IMG_Load("data/spritesheet.png"), SDL_FreeSurface};
    
    std::shared_ptr<SDL_Texture> texture{SDL_CreateTextureFromSurface(renderer.get(), imageSurface.get()), SDL_DestroyTexture};

    imageSurface.reset();

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer.get());
        SDL_RenderCopy(renderer.get(), texture.get(), NULL, NULL);
        SDL_RenderPresent(renderer.get());
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}