#include <game/rendering/window.hpp>

namespace Game {
    Window::Window(const Window_parameter param) : _param(param){
        auto create_window = [this](){ // définition d'une fonction lambda
            return SDL_CreateWindow(this->_param.title.c_str(), this->_param.position[0], this->_param.position[1], this->_param.size[0], this->_param.size[1], SDL_WINDOW_SHOWN);
        };

        this->_window = std::shared_ptr<SDL_Window>(create_window(), SDL_DestroyWindow);
    }

    std::shared_ptr<SDL_Window> Window::get_window() const noexcept{
        return this->_window;
    }
}