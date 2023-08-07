#include <game/rendering/texture/static_texture.hpp>

namespace Game {
    Static_texture::Static_texture(Texture_static_data data) : Texture_common<Texture_static_data>(data){
        Surface surface{this->_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, this->_renderer.get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
    }

    SDL_Texture* Static_texture::get_sdl_texture() override {
        return this->_texture.get();
    }
}