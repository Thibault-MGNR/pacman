#include <game/rendering/texture.hpp>
#include <game/rendering/surface.hpp>

void Game::Texture::initialize(){
    Game::Surface surface{this->_path};
    this->_texture = std::shared_ptr<SDL_Texture>{SDL_CreateTextureFromSurface(this->_renderer.get_renderer().get(), surface.get_surface().get()), SDL_DestroyTexture};
}

Game::Texture::Texture(Renderer &renderer, std::string path) : _renderer(renderer), _path(path){
    this->initialize();
}

Game::Texture::Texture(Renderer &renderer, std::string path, Texture_data data) : _renderer(renderer), _path(path), _data(data){
    this->initialize();
}

std::shared_ptr<SDL_Texture> Game::Texture::get_texture() const noexcept{
    return this->_texture;
}