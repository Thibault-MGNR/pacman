#include <game/object/reward/reward.hpp>

namespace Game {
    Reward::Reward(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, map, is_diplayable){
        this->_reward_id = -1;
    }

    Reward::Reward(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, data, map, is_diplayable){
        this->_reward_id = -1;
    }

    void Reward::draw_widget(int x_pm, int y_pm){
        for(int x = 0; x < 28; x++){
            for(int y = 0; y < 31; y++){
                auto map = this->_map->get_map();
                if (map[y][x] == this->_reward_id){
                    if(x_pm == x && y_pm == y){
                        map[y][x] = 0;
                        this->_map->set_map(map);
                    } else {
                        this->_data.position = std::array<int, 2>{x * 25, y * 25};
                        this->_draw();
                    }
                }
            }
        }
    }
}