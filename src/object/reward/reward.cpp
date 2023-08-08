#include <game/object/reward/reward.hpp>

namespace Game {
    void Reward::draw_reward(int x_pm, int y_pm){
        for(int x = 0; x < 28; x++){
            for(int y = 0; y < 31; y++){
                auto map = this->_map->get_map();
                if (map[y][x] == this->_reward_id){
                    if(x_pm == x && y_pm == y){
                        map[y][x] = 0;
                        this->_map->set_map(map);
                    } else {
                        this->_texture_placement.position = std::array<float, 2>{static_cast<float>(x * 25), static_cast<float>(y * 25)};
                        this->_draw();
                    }
                }
            }
        }
    }
}