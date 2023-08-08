#include <game/rendering/texture/texture.hpp>
#include <game/rendering/surface.hpp>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Texture::Texture(Texture_data data){
        // if(std::holds_alternative<Texture_animation_data>(data))
        //     this->_texture = std::make_unique<int>(9);
        if(std::holds_alternative<Texture_static_data>(data))
            this->_texture = std::make_unique<Static_texture>(std::get<Texture_static_data>(data));
    }

    SDL_Rect Texture::get_src_rect(){
        return std::visit([](auto&& texture){return texture->get_cropped_rectangle();}, this->_texture);
    }

    // const Renderer& Texture::get_renderer(){
    //     return std::visit([](auto& texture){return texture->get_renderer();}, this->_texture);
    // }
    const Renderer& Texture::get_renderer() {
    return std::visit([](const auto& texture) -> const Renderer& {
        return texture->get_renderer();
    }, this->_texture);
}

    SDL_Texture* Texture::get_sdl_texture(){
        return std::visit([](auto&& texture){return texture->get_sdl_texture();}, this->_texture);
    }
}