#include <game/game.hpp>
#include <game/object/character/character.hpp>
#include <iostream>
#include <array>

namespace Game {
    Character::Character(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, map, is_diplayable){}
    
    Character::Character(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Object(renderer, data, map, is_diplayable){}

    void Character::set_movement(const Movement mvt) noexcept{
        this->_next_movement = mvt;
    }

    void Character::draw(){
        if(this->_is_displayable){
            for(int i = 0; i < this->speed; i++){
                std::array<int, 2> last_pos = this->_data.position;

                switch (this->_next_movement){
                    case Movement::FORWARD:
                        this->_data.position[1]--;
                        break;
                    
                    case Movement::BACKWARD:
                        this->_data.position[1]++;
                        break;
                    
                    case Movement::LEFT:
                        this->_data.position[0]--;
                        break;
                    
                    case Movement::RIGHT:
                        this->_data.position[0]++;
                        break;
                    
                    default:
                        break;                
                }
                if(map_collision()){
                    set_movement(Movement::IDLE);
                    this->_data.position = last_pos;
                }
            }
            _draw();
        }
    }

    bool Character::map_collision(){
        int half = this->_data.dimension[1] / 2;
        int x_m = (int)((float)(this->_data.position[0] + half) / 3.125) / 8;
        int y_m = (int)((float)(this->_data.position[1] + half) / 3.125) / 8;
        switch (this->_next_movement){
            case Movement::FORWARD:
                if(check_map_collision_forward(x_m, y_m))
                    return true;
                break;
            
            case Movement::BACKWARD:
                if(check_map_collision_backward(x_m, y_m))
                    return true;
                break;
            
            case Movement::RIGHT:
                if(check_map_collision_right(x_m, y_m))
                    return true;
                break;
            
            case Movement::LEFT:
                if(check_map_collision_left(x_m, y_m))
                    return true;
                break;
            
            default:
                break;
        }
        return false;
    }

    bool Character::check_map_collision_forward(int x_m, int y_m){
        std::array<Map_sprite, 3> sprites;
        sprites[0] = this->_map->get_map_sprite_rect(x_m - 1, y_m - 1);
        sprites[1] = this->_map->get_map_sprite_rect(x_m, y_m - 1);
        sprites[2] = this->_map->get_map_sprite_rect(x_m + 1, y_m - 1);
        return check_map_sprites_collisions(sprites);
    }

    bool Character::check_map_collision_backward(int x_m, int y_m){
        std::array<Map_sprite, 3> sprites;
        sprites[0] = this->_map->get_map_sprite_rect(x_m - 1, y_m + 1);
        sprites[1] = this->_map->get_map_sprite_rect(x_m, y_m + 1);
        sprites[2] = this->_map->get_map_sprite_rect(x_m + 1, y_m + 1);
        return check_map_sprites_collisions(sprites);
    }

    bool Character::check_map_collision_right(int x_m, int y_m){
        std::array<Map_sprite, 3> sprites;
        sprites[0] = this->_map->get_map_sprite_rect(x_m + 1, y_m - 1);
        sprites[1] = this->_map->get_map_sprite_rect(x_m + 1, y_m);
        sprites[2] = this->_map->get_map_sprite_rect(x_m + 1, y_m + 1);
        return check_map_sprites_collisions(sprites);
    }

    bool Character::check_map_collision_left(int x_m, int y_m){
        std::array<Map_sprite, 3> sprites;
        sprites[0] = this->_map->get_map_sprite_rect(x_m - 1, y_m - 1);
        sprites[1] = this->_map->get_map_sprite_rect(x_m - 1, y_m);
        sprites[2] = this->_map->get_map_sprite_rect(x_m - 1, y_m + 1);
        return check_map_sprites_collisions(sprites);
    }

    bool Character::check_map_sprites_collisions(std::array<Map_sprite, 3> sprites){
        bool collision = false;
        for(int i = 0; i < 3; i++){
            int x = sprites[i].x;
            int y = sprites[i].y;
            if(this->_map->get_map()[y][x] == 1){
                if(test_collision(sprites[i].rect)){
                    collision = true;
                    SDL_SetRenderDrawColor(this->_renderer.get_renderer_ptr(), 255, 0, 0, 255);
                    SDL_RenderDrawRect(this->_renderer.get_renderer_ptr(), &sprites[i].rect);
                    SDL_SetRenderDrawColor(this->_renderer.get_renderer_ptr(), 0, 0, 0, 255);
                }
            }
        }
        return collision;
    }
}