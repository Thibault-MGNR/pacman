#include <game/rendering/renderer.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Renderer::Renderer(Window &window) : _window(window){
        this->_renderer = std::shared_ptr<SDL_Renderer>{SDL_CreateRenderer(this->_window.get_window().get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer};
        check_sdl_error();
    }

    SDL_Renderer *Renderer::get_renderer_ptr() const{
        return this->_renderer.get();
    }

    std::shared_ptr<SDL_Renderer> Renderer::get_renderer() const{
        return this->_renderer;
    }

    Renderer Renderer::operator=(const Renderer &renderer) const{
        return Renderer{renderer};
    }
}