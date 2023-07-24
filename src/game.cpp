#include <game/game.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Game::Game(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            Exit_with_error();
        }
        Window_parameter window_param;
        window_param.title = "Pac-man";
        window_param.size = {700, 1000};
        window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};
        this->_window = std::make_unique<Window>(Window{window_param});
        this->_renderer = std::make_unique<Renderer>(Renderer{*this->_window});
        this->_map = std::make_unique<Map>(Map{*this->_renderer});
        this->_run = true;
        this->_events = std::make_unique<SDL_Event>();
        this->_events_pool.add_event(this->_events->type, SDL_QUIT, [this](){this->quit();});
    }

    void Game::run(){
        while (this->_run) {
            while (SDL_PollEvent(this->_events.get())) {
                this->_events_pool.check_events();
            }

            if(SDL_RenderClear(this->_renderer->get_renderer_ptr()) < 0){
                Exit_with_error();
            }
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