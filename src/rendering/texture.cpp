#include <game/rendering/texture.hpp>
#include <game/rendering/surface.hpp>
#include <game/errors/SDL_error_handler.hpp>
#include <iostream>

namespace Game {
    void Texture::initialize_texture(){
        Surface surface{this->_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, this->_renderer.get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
    }

    Texture::Texture(const Renderer &renderer) : _renderer(renderer){}

    Texture::Texture(const Renderer &renderer, Texture_data data) : _renderer(renderer), _data(data){
        this->initialize_texture();
    }

    void Texture::draw_all() const{
        if(SDL_RenderCopy(this->_renderer.get_renderer_ptr(), this->_texture.get(), NULL, NULL) < 0){
            Exit_with_error();
        };
    }

    const SDL_Rect Texture::set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos) const{
        SDL_Rect rect;
        rect.w = dim[0];
        rect.h = dim[1];
        rect.x = pos[0];
        rect.y = pos[1];

        return rect;
    }

    void Texture::draw(){
        _draw();
    }

    void Texture::_draw() const{
        const SDL_Rect srcRect = set_rect(this->_data.crop_dimension, this->_data.crop_position);
        const SDL_Rect dstRect = set_rect(this->_data.dimension, this->_data.position);

        if(SDL_RenderCopy(this->_renderer.get_renderer_ptr(), this->_texture.get(), &srcRect, &dstRect) < 0){
            Exit_with_error();
        }
    }
}