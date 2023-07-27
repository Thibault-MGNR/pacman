#include <game/game.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Game::Game(){
        init_sdl();
        init_modules();
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
            int pac_m_x = this->_pac_man->get_map_pos()[0];
            int pac_m_y = this->_pac_man->get_map_pos()[1];

            this->_coins->draw_widget(pac_m_x, pac_m_y);
            this->_pac_man->draw();
            SDL_RenderPresent(this->_renderer->get_renderer_ptr());

            this->_fps_manager.manage();
        }
    }

    void Game::quit(){
        this->_run = false;
    }

    Game::~Game(){
        SDL_Quit();
    }

    void Game::init_window(){
        Window_parameter window_param;
        window_param.title = "Pac-man";
        window_param.size = {700, 1000};
        window_param.position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};
        this->_window = std::make_unique<Window>(Window{window_param});
    }

    void Game::init_sdl(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            Exit_with_error();
        }
    }

    void Game::init_modules(){
        init_window();
        this->_renderer = std::make_unique<Renderer>(Renderer{*this->_window});
        this->_map = std::make_shared<Map>(Map{*this->_renderer});
        this->_run = true;
        this->_events = std::make_shared<SDL_Event>();
        this->_events_pool.add_event(this->_events->type, SDL_QUIT, [this](){this->quit();});
        this->_fps_manager = FPS_manager{60};
        init_pacman();
        init_coins();
    }

    void Game::init_pacman(){

        this->_pac_man = std::make_unique<Pac_man>(Pac_man{*this->_renderer, this->_map});
        this->_pac_man->init_events(this->_events_pool, this->_events);
    }

    void Game::init_coins(){
        this->_coins = std::make_unique<Coins>(Coins{*this->_renderer, this->_map});
    }
}