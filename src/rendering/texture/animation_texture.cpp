#include <game/rendering/texture/animation_texture.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Animation_texture::Animation_texture(Texture_animation_data data) : Texture_common<Texture_animation_data>(data){
        Surface surface{this->_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, this->_data.renderer.get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
    }

    SDL_Texture* Animation_texture::get_sdl_texture() {
        return this->_texture.get();
    }

    SDL_Rect Animation_texture::get_cropped_rectangle() {
        return set_rect(this->_data.sprites_dim, this->_data.sprites_sheet_pos); // temporaire
    }

    const Renderer& Animation_texture::get_renderer() {
        return this->_data.renderer;
    }
}