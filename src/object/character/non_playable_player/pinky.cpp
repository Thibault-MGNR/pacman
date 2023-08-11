#include <game/object/character/non_playable_player/pinky.hpp>

namespace Game {
    Pinky::Pinky(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Ghost(map, is_diplayable) {
        Texture_animation_data data;
        this->_texture_placement.dimension = {25, 25};
        this->_texture_placement.position = {287, 350};
        data.path = "data/spritesheet2.png";
        data.srites_delay = 150;
        data.sprites_number = 2;
        data.sprites_dim = {16, 32};
        data.sprites_sheet_dim = {32, 16};
        data.sprites_sheet_pos = {464, 176};
        this->_texture = std::make_unique<Animation_texture>(renderer, data);

        _define_texture();
        this->_has_motion_responsive_texture = true;
        _update();
    }

    void Pinky::_define_idle_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::IDLE)]; 
        data.sprites_sheet_pos = {464, 176};
    }

    void Pinky::_define_forward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::FORWARD)]; 
        data.sprites_sheet_pos = {520, 80};
    }

    void Pinky::_define_backward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::BACKWARD)]; 
        data.sprites_sheet_pos = {552, 80};
    }

    void Pinky::_define_right_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::RIGHT)]; 
        data.sprites_sheet_pos = {456, 80};
    }

    void Pinky::_define_left_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::LEFT)]; 
        data.sprites_sheet_pos = {488, 86};
    }

    void Pinky::_define_texture(){
        _define_common_texture_data();
        _define_forward_texture();
        _define_backward_texture();
        _define_left_texture();
        _define_right_texture();
        _define_idle_texture();
    }

    void Pinky::_define_common_texture_data(){
        for(auto& element : this->_motion_responsive_texture_animation_data){
            element.path = "data/spritesheet2.png";
            element.srites_delay = 150;
            element.sprites_number = 2;
            element.sprites_dim = {16, 16};
            element.sprites_sheet_dim = {32, 16};
        }
    }

}