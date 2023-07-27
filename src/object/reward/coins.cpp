#include <game/object/reward/coins.hpp>

namespace Game {
    Coins::Coins(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Reward(renderer, map, is_diplayable){
        this->_reward_id = 3;
        this->_data.path = "data/spritesheet2.png";
        this->_data.crop_dimension = {8, 8};
        this->_data.crop_position = {8, 8};
        this->_data.dimension = {25, 25};
        this->initialize_texture();
    }
}