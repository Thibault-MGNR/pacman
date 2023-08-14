#include <game/rendering/fps_manager.hpp>
#include <SDL2/SDL.h>
#include <iostream>

namespace Game {
    FPS_manager::FPS_manager(){}

    FPS_manager::FPS_manager(const int max_FPS) : _max_FPS(max_FPS){
        this->_last_ticks = SDL_GetTicks();
        this->_timeout = 1000 / this->_max_FPS;
        this->_count = 0;
    }

    void FPS_manager::manage(){
        this->_count++;
        int now = SDL_GetTicks();
        int delta = now - this->_last_ticks;

        if(delta < this->_timeout){
            SDL_Delay(this->_timeout - delta);
            if(this->_count >= 60 * 10){
                std::cout << "FPS: " << 1000 / (SDL_GetTicks() - this->_last_ticks) << std::endl;
                this->_count = 0;
            }
        }

        this->_last_ticks = SDL_GetTicks();
    }

    void FPS_manager::set_max_FPS(const int max){
        this->_max_FPS = max;
        this->_timeout = 1000 / this->_max_FPS;
    }
}