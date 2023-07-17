#include <game/game.hpp>

/*
int main(){
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
*/

namespace Game {
    Game::Game(){
        SDL_Init(SDL_INIT_VIDEO);
        Window_parameter window_param;
        window_param.title = "Pac-man";
        window_param.size = {700, 1000};
        window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};
        this->_window = std::make_unique<Window>(Window{window_param});
        this->_renderer = std::make_unique<Renderer>(Renderer{*this->_window});
        this->_map = std::make_unique<Map>(Map{*this->_renderer});
        this->_run = true;

        this->_events_pool.add_event(this->_events->type, SDL_QUIT, [this](){ this->quit();});
    }

    void Game::run(){
        while (this->_run) {
            while (SDL_PollEvent(this->_events.get())) {
                this->_events_pool.check_events();
            }

            SDL_RenderClear(this->_renderer->get_renderer_ptr());
            this->_map->draw();
            SDL_RenderPresent(this->_renderer->get_renderer_ptr());
        }
    }

    void Game::quit(){
        this->_run = false;
    }

    Game::~Game(){
        SDL_Quit();
    }
}