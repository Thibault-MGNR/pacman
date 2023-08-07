#include <game/rendering/texture/texture.hpp>
#include <game/rendering/surface.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Texture::Texture(Texture_data data){
        if(std::holds_alternative<Texture_animation_data>(data))
            this->_texture = std::make_unique<Animation_texture>(data);
        else if(std::holds_alternative<Texture_static_data>(data))
            this->_texture = std::make_unique<Static_texture>(data);
    }

    SDL_Texture* Texture::get_sdl_texture(){
        return std::visit([](const auto& texture){return texture.get_sdl_texture();}, this->_texture);
    }
}