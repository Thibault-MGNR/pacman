#include <game/object/reward/pacgum.hpp>
#include <game/rendering/texture/static_texture.hpp>

namespace Game {
    Pacgum::Pacgum(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Reward(map, is_diplayable){
        this->_reward_id = 4;

        Texture_static_data data;
        data.crop_dimension = {8, 8};
        data.crop_position = {8, 24};
        this->_texture_placement.dimension = {25, 25};
        data.path = "data/spritesheet2.png";

        this->_texture = std::make_unique<Static_texture>(renderer, data);
    }
}