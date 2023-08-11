#pragma once

#include <game/object/character/character.hpp>

namespace Game {
    class Non_playable_player : public Character {
        public:
            using Character::Character;
    };
}