#pragma once

#include <game/object/character/character.hpp>
#include <game/algorithm_suite/a_star.hpp>

namespace Game {
    class Non_playable_player : public Character {
        public:
            Non_playable_player() = delete;
            Non_playable_player(std::shared_ptr<Map> map, bool is_diplayable = true);
        
        protected:
            Path_finding _path_finder;
    
    };
}