#include <game/rendering/fps_manager.hpp>
#include <SDL2/SDL.h>
#include <iostream>

namespace Game {
    FPS_manager::FPS_manager(){}

    FPS_manager::FPS_manager(const int max_FPS) : _max_FPS(max_FPS){
        this->_last_ticks = SDL_GetTicks();
        this->_timeout = 1000 / this->_max_FPS;
    }

    void FPS_manager::manage(){
        int now = SDL_GetTicks();
        int delta = now - this->_last_ticks;

        if(delta < this->_timeout){
            SDL_Delay(this->_timeout - delta);
        }

        this->_last_ticks = SDL_GetTicks();
    }

    void FPS_manager::set_max_FPS(const int max){
        this->_max_FPS = max;
        this->_timeout = 1000 / this->_max_FPS;
    }
}