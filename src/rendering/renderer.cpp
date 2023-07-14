#include <game/rendering/renderer.hpp>

Game::Renderer::Renderer(Window &window) : _window(window){
    this->_renderer = std::shared_ptr<SDL_Renderer>{SDL_CreateRenderer(this->_window.get_window().get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer};
}

SDL_Renderer *Game::Renderer::get_renderer_ptr() const{
    return this->_renderer.get();
}

std::shared_ptr<SDL_Renderer> Game::Renderer::get_renderer() const{
    return this->_renderer;
}