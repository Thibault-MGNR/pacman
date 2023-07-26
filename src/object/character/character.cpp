#include <game/game.hpp>
#include <game/object/character/character.hpp>
#include <iostream>

namespace Game {
    Character::Character(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, map, is_diplayable){}
    
    Character::Character(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, data, map, is_diplayable){}

    void Character::set_movement(const Movement mvt) noexcept{
        this->_next_movement = mvt;
    }

    void Character::draw(){
        if(this->_is_displayable){
            std::array<int, 2> last_pos = this->_data.position;

            switch (this->_next_movement){
                case Movement::FORWARD:
                    this->_data.position[1] -= this->speed;
                    break;
                
                case Movement::BACKWARD:
                    this->_data.position[1] += this->speed;
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
            if(map_collision()){
                set_movement(Movement::IDLE);
                this->_data.position = last_pos;
            }

            _draw();
        }
    }

    bool Character::map_collision(){
        int x_m, y_m;
        switch (this->_next_movement){
            case Movement::FORWARD:
                x_m = (int)((float)this->_data.position[0] / 3.125) / 8;
                y_m = (int)((float)this->_data.position[1] / 3.125) / 8;
                if(this->_map->get_map()[y_m][x_m] == 1)
                    return true;
                break;
            
            case Movement::BACKWARD:
                x_m = (int)((float)this->_data.position[0] / 3.125) / 8;
                y_m = (int)((float)(this->_data.position[1] + this->_data.dimension[1]) / 3.125) / 8;
                if(this->_map->get_map()[y_m][x_m] == 1)
                    return true;
                break;
            
            case Movement::RIGHT:
                x_m = (int)((float)(this->_data.position[0] + this->_data.dimension[0]) / 3.125) / 8;
                y_m = (int)((float)this->_data.position[1] / 3.125) / 8;
                if(this->_map->get_map()[y_m][x_m] == 1)
                    return true;
                break;
            
            case Movement::LEFT:
                x_m = (int)((float)this->_data.position[0] / 3.125) / 8;
                y_m = (int)((float)this->_data.position[1] / 3.125) / 8;
                if(this->_map->get_map()[y_m][x_m] == 1)
                    return true;
                break;
            
            default:
                break;
        }
        return false;
    }
}