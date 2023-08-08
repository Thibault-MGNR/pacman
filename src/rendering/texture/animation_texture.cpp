#include <game/rendering/texture/animation_texture.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Animation_texture::Animation_texture(const Renderer &renderer,  Texture_animation_data data) : Texture(renderer, data){
        Texture_animation_data animation_data = get_animation_data();
        Surface surface{animation_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, get_renderer().get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};
    }

    SDL_Texture* Animation_texture::get_sdl_texture() {
        return this->_texture.get();
    }

    SDL_Rect Animation_texture::get_src_rect() {
        return SDL_Rect{0}; // temporaire
    }

    void Animation_texture::_update_frame(){
        switch(get_animation_data().read_dir){
            case Sprites_read_direction::TOP_RIGHT_TO_BOTTOM_LEFT:
                break;
            case Sprites_read_direction::TOP_LEFT_TO_BOTTOM_RIGHT:
                break;
            case Sprites_read_direction::BOTTOM_RIGHT_TO_TOP_LEFT:
                break;
            case Sprites_read_direction::BOTTOM_LEFT_TO_TOP_RIGHT:
                break;
            default:
                throw std::runtime_error("Read drection doesn't exist");
        }
    }
}