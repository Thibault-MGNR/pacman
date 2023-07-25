#include <game/game.hpp>
#include <game/object/character/character.hpp>

namespace Game {
    Character::Character(const Renderer &renderer, bool is_diplayable) : Object(renderer, is_diplayable){}
    
    Character::Character(const Renderer &renderer, Texture_data data, bool is_diplayable) : Object(renderer, data, is_diplayable){}

    void Character::set_movement(const Movement mvt) noexcept{
        this->_next_movement = mvt;
    }

    void Character::draw(){
        if(this->_is_displayable){
            switch (this->_next_movement){
                case Movement::FORWARD:
                    this->_data.position[1] += this->speed;
                    break;
                case Movement::BACKWARD:
                    this->_data.position[1] -= this->speed;
                    break;
                case Movement::LEFT:
                    this->_data.position[0] -= this->speed;
                    break;
                case Movement::RIGHT:
                    this->_data.position[0] += this->speed;
                    break;
                default:
                    break;
            }
            _draw();
        }
    }
}