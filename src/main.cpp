#include <iostream>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <game/game.hpp>
#include <game/map/map.hpp>
#include <game/events/events_pool.hpp>

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    Game::Window_parameter window_param;
    window_param.title = "Pac-man";
    window_param.size = {700, 1000};
    window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};

    Game::Window window{window_param};
    Game::Renderer renderer{window};
    Game::Map map{std::make_shared<Game::Renderer>(renderer)};

    bool quit = false;
    auto event = std::make_shared<SDL_Event>();

    auto a = [&quit](){
        quit = true;
    };

    Game::Events_pool event_pool;
    
    std::shared_ptr<uint32_t> type(&event->type);
    event_pool.add_event(type, SDL_QUIT, a);

    while (!quit) {
        while (SDL_PollEvent(event.get())) {
            event_pool.check_events();
        }

        SDL_RenderClear(renderer.get_renderer_ptr());
        map.draw();
        SDL_RenderPresent(renderer.get_renderer_ptr());
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}