#include <game/object/character/non_playable_player/non_playable_player.hpp>

namespace Game {
    Non_playable_player::Non_playable_player(std::shared_ptr<Map> map, bool is_diplayable) : Character(map, is_diplayable){
        if(!this->_path_finder.create(map)){
            throw std::runtime_error("path finder init error");
        }
    }
}