#include <game/object/reward/pacgum.hpp>

namespace Game {
    Pacgum::Pacgum(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Reward(map, is_diplayable){
        this->_reward_id = 4;

        Texture_animation_data data;
        data.sprites_dim = {10, 10};
        data.sprites_sheet_pos = {599, 15};
        data.sprites_sheet_dim = {18, 10};
        data.srites_delay = 200;
        data.sprites_number = 2;
        data.path = "data/spritesheet2.png";
        this->_texture_placement.dimension = {25, 25};

        this->_texture = std::make_unique<Animation_texture>(renderer, data);
    }
}