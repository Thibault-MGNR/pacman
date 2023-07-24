#include <game/game.hpp>
#include <game/object/character/character.hpp>

namespace Game {
    Character::Character(const Renderer &renderer) : Object(renderer){}

    Character::Character(const Renderer &renderer, bool is_diplayable) : Object(renderer, is_diplayable){}

    Character::Character(const Renderer &renderer, Texture_data data) : Object(renderer, data){}
    
    Character::Character(const Renderer &renderer, Texture_data data, bool is_diplayable) : Object(renderer, data, is_diplayable){}

    void Character::set_movement(const Movement mvt) noexcept{
        this->_next_movement = mvt;
    }
}