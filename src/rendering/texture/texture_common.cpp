#include <game/rendering/texture/texture_common.hpp>

namespace Game {
    const SDL_Rect set_rect(const std::array<float, 2> &dim, const std::array<float, 2> &pos){
        SDL_Rect rect;
        rect.w = static_cast<int>(dim[0]);
        rect.h = static_cast<int>(dim[1]);
        rect.x = static_cast<int>(pos[0]);
        rect.y = static_cast<int>(pos[1]);

        return rect;
    }

    const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos){
        SDL_Rect rect;
        rect.w = dim[0];
        rect.h = dim[1];
        rect.x = pos[0];
        rect.y = pos[1];

        return rect;
    }

    const Texture_placement set_tp_from_sdl_rect(const SDL_Rect& rect){
        Texture_placement tp;
        tp.dimension[0] = rect.h;
        tp.dimension[1] = rect.w;
        tp.position[0] = rect.x;
        tp.position[1] = rect.y;

        return tp;
    }

    Texture::Texture(const Renderer &renderer, Texture_animation_data data) : _renderer(renderer){
        this->_type_of_texture = Type::ANIMATED;
        this->_data_animation = data;
    }

    Texture::Texture(const Renderer &renderer, Texture_static_data data) : _renderer(renderer){
        this->_type_of_texture = Type::STATIC;
        this->_data_static = data;
    }

    Texture::~Texture(){}

    void Texture::set_data(Texture_animation_data data){
        if(this->_type_of_texture == Type::ANIMATED){
            this->_data_animation = data;
            update_texture();
        }
    }

    void Texture::set_data(Texture_static_data data){
        if(this->_type_of_texture == Type::STATIC){
            this->_data_static = data;
            update_texture();
        }
    }

    void Texture::update_texture(){}

    Texture_animation_data Texture::get_animation_data(){
        return this->_data_animation;
    }

    Texture_static_data Texture::get_static_data(){
        return this->_data_static;
    }

    const Renderer& Texture::get_renderer(){
        return this->_renderer;
    }
}