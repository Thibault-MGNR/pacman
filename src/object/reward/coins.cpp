#include <game/object/reward/coins.hpp>

namespace Game {
    Coins::Coins(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Reward(map, is_diplayable){
        this->_reward_id = 3;

        Texture_static_data data{renderer};
        data.crop_dimension = {8, 8};
        data.crop_position = {8, 8};
        this->_texture_placement.dimension = {25, 25};
        data.path = "data/spritesheet2.png";

        this->_texture = std::make_unique<Texture>(data);
    }
}