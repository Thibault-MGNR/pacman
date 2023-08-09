#include <game/game.hpp>
#include <game/object/character/character.hpp>
#include <iostream>
#include <array>
#include <iterator>

namespace Game {
    void Character::set_movement(const Movement mvt) noexcept{
        this->_desired_movement = mvt;
    }

    void Character::_update(){
        if(this->_has_motion_responsive_texture){
            switch (this->_texture->get_type()) {
                case Texture_type::STATIC:
                    _update_static_texture();
                    break;
                case Texture_type::ANIMATED:
                    _update_animated_texture();
                    break;
                
                default:
                    throw std::runtime_error("Incompatible motion type");
                    break;
            }
        }
    }

    void Character::_update_static_texture(){
        if(this->_texture->get_static_data() != this->_motion_responsive_texture_static_data[static_cast<int>(this->_next_movement)]){
            this->_texture->set_data(this->_motion_responsive_texture_static_data[static_cast<int>(this->_next_movement)]);
        }
    }

    void Character::_update_animated_texture(){
        if(this->_texture->get_animation_data() != this->_motion_responsive_texture_animation_data[static_cast<int>(this->_next_movement)]){
            this->_texture->set_data(this->_motion_responsive_texture_animation_data[static_cast<int>(this->_next_movement)]);
        }
    }

    void Character::draw(){
        if(this->_is_displayable){
            for(int i = 0; i < this->speed; i++){
                std::array<float, 2> last_pos = this->_texture_placement.position;
                if(this->_desired_movement != Movement::IDLE){
                    move(this->_desired_movement);
                    if(map_collision(this->_desired_movement)){
                        this->_texture_placement.position = last_pos;
                        process_next_movement_with_collision(last_pos);
                    } else {
                        this->_next_movement = this->_desired_movement;
                        this->_desired_movement = Movement::IDLE;
                    }
                } else {
                    process_next_movement_with_collision(last_pos);
                }
            }
            _update();
            _draw();
        }
    }

    void Character::process_next_movement_with_collision(std::array<float, 2> last_pos){
        move(this->_next_movement);
        if(map_collision(this->_next_movement)){
            this->_texture_placement.position = last_pos;
            this->_next_movement = Movement::IDLE;
            this->_desired_movement = Movement::IDLE;
        }
    }
    
    void Character::move(Movement movement){
        switch (movement){
            case Movement::FORWARD:
                this->_texture_placement.position[1]--;
                break;
            
            case Movement::BACKWARD:
                this->_texture_placement.position[1]++;
                break;
            
            case Movement::LEFT:
                this->_texture_placement.position[0]--;
                break;
            
            case Movement::RIGHT:
                this->_texture_placement.position[0]++;
                break;
            
            default:
                break;                
        }
    }

    bool Character::map_collision(Movement mov){
        int half = this->_texture_placement.dimension[1] / 2;
        int x_m = (int)((float)(this->_texture_placement.position[0] + half) / 3.125) / 8;
        int y_m = (int)((float)(this->_texture_placement.position[1] + half) / 3.125) / 8;
        switch (mov){
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
            auto collisions_id{std::begin(this->collisions_set)};
            while(collisions_id != std::end(this->collisions_set)){
                if(this->_map->get_map()[y][x] == *collisions_id){
                    if(test_collision(sprites[i].rect))
                        collision = true;
                }
                collisions_id++;
            }
        }
        return collision;
    }
}