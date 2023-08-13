#include <game/object/character/non_playable_player/inky.hpp>
#include <SDL2/SDL.h>

namespace Game {
    Inky::Inky(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Ghost(renderer, map, is_diplayable) {
        Texture_animation_data data = this->_texture->get_animation_data();
        this->_texture_placement.position = {387, 350};
        data.sprites_sheet_pos = {464, 176};
        this->_texture->set_data(data);
        _define_texture();
        _update();
    }

    void Inky::_define_idle_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::IDLE)]; 
        data.sprites_sheet_pos = {464, 192};
    }

    void Inky::_define_forward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::FORWARD)]; 
        data.sprites_sheet_pos = {520, 96};
    }

    void Inky::_define_backward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::BACKWARD)]; 
        data.sprites_sheet_pos = {552, 96};
    }

    void Inky::_define_right_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::RIGHT)]; 
        data.sprites_sheet_pos = {456, 96};
    }

    void Inky::_define_left_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::LEFT)]; 
        data.sprites_sheet_pos = {488, 96};
    }

    void Inky::draw_path(int x, int y){
        this->_path_finder.set_node_start(1, 1);
        this->_path_finder.set_node_end(x, y);
        this->_path_finder.solve_AStar();
        auto path = this->_path_finder.get_path();
        SDL_SetRenderDrawColor(this->_texture->get_renderer().get_renderer_ptr(), 0, 255, 0, 255);
        while(!path.empty()){
            auto pos = path.top();
            SDL_Rect rect;
            rect.h = 25;
            rect.w = 25;
            rect.x = pos.first * 25;
            rect.y = pos.second * 25;
            SDL_RenderDrawRect(this->_texture->get_renderer().get_renderer_ptr(), &rect);
            path.pop();
        }
        SDL_SetRenderDrawColor(this->_texture->get_renderer().get_renderer_ptr(), 0, 0, 0, 255);
    }
}