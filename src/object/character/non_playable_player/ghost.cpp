#include <game/object/character/non_playable_player/ghost.hpp>

namespace Game {
    Ghost::Ghost(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Non_playable_player(map, is_diplayable){
        this->_texture_placement.dimension = {25, 25};
        Texture_animation_data data;
        data.path = "data/spritesheet2.png";
        data.srites_delay = 150;
        data.sprites_number = 2;
        data.sprites_dim = {16, 32};
        data.sprites_sheet_dim = {32, 16};
        data.sprites_sheet_pos = {0, 0};
        this->_texture = std::make_unique<Animation_texture>(renderer, data);
        this->_has_motion_responsive_texture = true;
    }

    void Ghost::_define_texture(){
        _define_common_texture_data();
        _define_forward_texture();
        _define_backward_texture();
        _define_left_texture();
        _define_right_texture();
        _define_idle_texture();
    }

    void Ghost::_define_common_texture_data(){
        for(auto& element : this->_motion_responsive_texture_animation_data){
            element.path = "data/spritesheet2.png";
            element.srites_delay = 150;
            element.sprites_number = 2;
            element.sprites_dim = {16, 16};
            element.sprites_sheet_dim = {32, 16};
        }
    }
}