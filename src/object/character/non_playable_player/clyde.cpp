#include <game/object/character/non_playable_player/clyde.hpp>

namespace Game {
    Clyde::Clyde(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Ghost(renderer, map, is_diplayable) {
        Texture_animation_data data = this->_texture->get_animation_data();
        this->_texture_placement.position = {337, 275};
        data.sprites_sheet_pos = {464, 176};
        this->_texture->set_data(data);
        _define_texture();
        _update();
    }

    void Clyde::_define_idle_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::IDLE)]; 
        data.sprites_sheet_pos = {464, 208};
    }

    void Clyde::_define_forward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::FORWARD)]; 
        data.sprites_sheet_pos = {520, 112};
    }

    void Clyde::_define_backward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::BACKWARD)]; 
        data.sprites_sheet_pos = {552, 112};
    }

    void Clyde::_define_right_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::RIGHT)]; 
        data.sprites_sheet_pos = {456, 112};
    }

    void Clyde::_define_left_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::LEFT)]; 
        data.sprites_sheet_pos = {488, 112};
    }
}