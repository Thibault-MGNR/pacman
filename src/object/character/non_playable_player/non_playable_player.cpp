#include <game/object/character/non_playable_player/non_playable_player.hpp>

namespace Game {
    Non_playable_player::Non_playable_player(std::shared_ptr<Map> map, bool is_diplayable) : Character(map, is_diplayable){
        if(!this->_path_finder.create(map)){
            throw std::runtime_error("path finder init error");
        }
    }

    void Non_playable_player::draw_path(int x, int y){
        auto my_pos = get_map_pos();
        this->_path_finder.set_node_start(my_pos[0], my_pos[1]);
        this->_path_finder.set_node_end(x, y);
        this->_path_finder.solve_AStar();
        this->_path = this->_path_finder.get_path();
        update_movement();
        SDL_SetRenderDrawColor(this->_texture->get_renderer().get_renderer_ptr(), 0, 255, 0, 255);
        auto drawing_path = this->_path;
        while(!drawing_path.empty()){
            auto pos = drawing_path.top();
            SDL_Rect rect;
            rect.h = 25;
            rect.w = 25;
            rect.x = pos.first * 25;
            rect.y = pos.second * 25;
            SDL_RenderDrawRect(this->_texture->get_renderer().get_renderer_ptr(), &rect);
            drawing_path.pop();
        }
        SDL_SetRenderDrawColor(this->_texture->get_renderer().get_renderer_ptr(), 0, 0, 0, 255);
    }

    void Non_playable_player::update_movement(){
        if(this->_path.empty()){
            set_movement(Movement::IDLE);
            return;
        }
        
        auto targeted_map_pos = this->_path.top();
        auto my_pos = this->_texture_placement.position;

        if(targeted_map_pos.first * 25 > my_pos[0])
            set_movement(Movement::RIGHT);
        else if(targeted_map_pos.first * 25 < my_pos[0])
            set_movement(Movement::LEFT);
        else if(targeted_map_pos.second * 25 > my_pos[1])
            set_movement(Movement::BACKWARD);
        else if(targeted_map_pos.second * 25 < my_pos[1])
            set_movement(Movement::FORWARD);
        else 
            set_movement(Movement::IDLE);
        
        if(targeted_map_pos.first * 25 - my_pos[0] > 500)
            set_movement(Movement::LEFT);
        else if(my_pos[0] - targeted_map_pos.first * 25 > 500)
            set_movement(Movement::RIGHT);
    }
}