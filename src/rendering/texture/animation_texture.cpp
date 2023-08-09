#include <game/rendering/texture/animation_texture.hpp>
#include <game/errors/SDL_error_handler.hpp>
#include <iostream>

namespace Game {
    Animation_texture::Animation_texture(const Renderer &renderer,  Texture_animation_data data) : Texture(renderer, data){
        update_texture();
    }

    void Animation_texture::update_texture() {
        Texture_animation_data animation_data = get_animation_data();
        Surface surface{animation_data.path};
        this->_texture = std::shared_ptr<SDL_Texture>{Check(SDL_CreateTextureFromSurface, get_renderer().get_renderer_ptr(), surface.get_surface().get()), SDL_DestroyTexture};

        this->_sprites_sheet_grid[0] = animation_data.sprites_sheet_dim[0] / animation_data.sprites_dim[0];
        this->_sprites_sheet_grid[1] = (animation_data.sprites_number / this->_sprites_sheet_grid[0]) + 1;
        this->_current_frame.dimension[0] = static_cast<float>(animation_data.sprites_dim[0]);
        this->_current_frame.dimension[1] = static_cast<float>(animation_data.sprites_dim[1]);
        _update_frame();
    }

    SDL_Texture* Animation_texture::get_sdl_texture() {
        return this->_texture.get();
    }

    SDL_Rect Animation_texture::get_src_rect() {
        int delta_time = SDL_GetTicks() - this->_frame_tick;
        if(delta_time > get_animation_data().srites_delay)
            _update_frame();
        
        return set_rect(this->_current_frame.dimension, this->_current_frame.position);
    }

    void Animation_texture::_update_frame() {
        switch(get_animation_data().read_dir){
            case Sprites_read_direction::TOP_RIGHT_TO_BOTTOM_LEFT:
                _update_frame_TRBL();
                break;
            case Sprites_read_direction::TOP_LEFT_TO_BOTTOM_RIGHT:
                _update_frame_TLBR();
                break;
            case Sprites_read_direction::BOTTOM_RIGHT_TO_TOP_LEFT:
                _update_frame_BRTL();
                break;
            case Sprites_read_direction::BOTTOM_LEFT_TO_TOP_RIGHT:
                _update_frame_BLTR();
                break;
            default:
                throw std::runtime_error("Read direction doesn't exist");
                break;
        }

        this->_current_number_frame++;
        Texture_animation_data animation_data = get_animation_data();
        if(animation_data.sprites_number <= this->_current_number_frame)
            this->_current_number_frame = 0;
        
        this->_frame_tick = SDL_GetTicks();
    }

    void Animation_texture::_update_frame_TRBL(){

    }

    void Animation_texture::_update_frame_TLBR(){
        float pos_x_grid = static_cast<float>(this->_current_number_frame % this->_sprites_sheet_grid[0]);
        float pos_y_grid = static_cast<float>(this->_current_number_frame / this->_sprites_sheet_grid[0]);
        this->_current_frame.position[0] = pos_x_grid * get_animation_data().sprites_dim[0] + get_animation_data().sprites_sheet_pos[0];
        this->_current_frame.position[1] = pos_y_grid * get_animation_data().sprites_dim[1] + get_animation_data().sprites_sheet_pos[1];
    }

    void Animation_texture::_update_frame_BRTL(){

    }

    void Animation_texture::_update_frame_BLTR(){

    }
}