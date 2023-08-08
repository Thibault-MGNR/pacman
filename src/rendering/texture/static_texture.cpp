#include <game/rendering/texture/static_texture.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Static_texture::Static_texture(const Renderer &renderer, Texture_static_data data) : Texture(renderer, data){
        Texture_static_data static_data = get_static_data();
        Surface surface{static_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, get_renderer().get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
    }

    SDL_Texture* Static_texture::get_sdl_texture() {
        return this->_texture.get();
    }

    SDL_Rect Static_texture::get_src_rect() {
        Texture_static_data static_data = get_static_data();
        return set_rect(static_data.crop_dimension, static_data.crop_position);
    }
}