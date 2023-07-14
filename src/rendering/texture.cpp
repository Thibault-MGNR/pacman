#include <game/rendering/texture.hpp>
#include <game/rendering/surface.hpp>

Game::Texture::Texture(){}

void Game::Texture::initialize(){
    Game::Surface surface{this->_path};
    this->_texture = std::shared_ptr<SDL_Texture>{SDL_CreateTextureFromSurface(this->_renderer.get()->get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
}

Game::Texture::Texture(std::shared_ptr<Renderer> renderer, std::string path) : _renderer(renderer), _path(path){
    this->initialize();
}

Game::Texture::Texture(std::shared_ptr<Renderer> renderer, std::string path, Texture_data data) : _renderer(renderer), _path(path), _data(data){
    this->initialize();
}

std::shared_ptr<SDL_Texture> Game::Texture::get_texture() const noexcept{
    return this->_texture;
}

void Game::Texture::draw_all() const{
    SDL_RenderCopy(this->_renderer.get()->get_renderer_ptr(), this->_texture.get(), NULL, NULL);
}

void Game::Texture::draw() const{
    SDL_Rect srcRect;
    srcRect.w = this->_data.crop_dimension[0];
    srcRect.h = this->_data.crop_dimension[1];
    srcRect.x = this->_data.crop_position[0];
    srcRect.y = this->_data.crop_position[1];

    SDL_Rect dstRect;
    dstRect.h = this->_data.dimension[1];
    dstRect.w = this->_data.dimension[0];
    dstRect.x = this->_data.position[0];
    dstRect.y = this->_data.position[1];

    SDL_RenderCopy(this->_renderer.get()->get_renderer_ptr(), this->_texture.get(), &srcRect, &dstRect);
}