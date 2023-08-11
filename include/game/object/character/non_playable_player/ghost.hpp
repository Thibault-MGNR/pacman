#pragma once
#include <game/object/character/non_playable_player/non_playable_player.hpp>

namespace Game {
    class Ghost : public Non_playable_player {
        public:
            using Non_playable_player::Non_playable_player;
    };
}