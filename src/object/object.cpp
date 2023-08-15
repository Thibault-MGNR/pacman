#include <game/game.hpp>
#include <vector>
#include <SDL2/SDL.h>
#include <game/errors/SDL_error_handler.hpp>

namespace Game {
    Object::Object(std::shared_ptr<Map> map, bool is_diplayable) : _is_displayable(is_diplayable), _map(map){}

    Texture_placement Object::get_texture_placement() const{
        return this->_texture_placement;
    }

    bool Object::test_collision(Object &obj){
        Texture_placement tp = obj.get_texture_placement();
        SDL_Rect rect = set_rect(tp.dimension, tp.position);
        return test_collision(rect);
    }

    bool Object::test_collision(SDL_Rect rect){
        std::vector<bool> is_overlap;
        Texture_placement a = this->_texture_placement;
        Texture_placement b = set_tp_from_sdl_rect(rect);
        is_overlap.push_back(a.position[0] < b.position[0] + b.dimension[0]);
        is_overlap.push_back(a.position[0] + a.dimension[0] > b.position[0]);
        is_overlap.push_back(a.position[1] < b.position[1] + b.dimension[1]);
        is_overlap.push_back(a.dimension[1] + a.position[1] > b.position[1]);

        if(is_overlap == std::vector<bool>{true, true, true, true})
            return true;

        return false;
    }

    void Object::draw(){
        if(this->_is_displayable)
            _draw();
    }

    void Object::_draw(){
        if(this->_texture_placement.position[0] > 701)
            this->_texture_placement.position[0] = -24;
        if(this->_texture_placement.position[0] < -25)
            this->_texture_placement.position[0] = 700;
            
        const SDL_Rect srcRect = this->_texture->get_src_rect();
        const SDL_Rect dstRect = set_rect(this->_texture_placement.dimension, this->_texture_placement.position);

        if(SDL_RenderCopy(this->_texture->get_renderer().get_renderer_ptr(), this->_texture->get_sdl_texture(), &srcRect, &dstRect) < 0){
            Exit_with_error();
        }
    }

    std::array<int, 2> Object::get_map_pos(){
        std::array<int, 2> pos;
        int half = this->_texture_placement.dimension[0] / 2;
        pos[0] = (this->_texture_placement.position[0] + half) / 3.125 / 8;
        pos[1] = (this->_texture_placement.position[1] + half) / 3.125 / 8;
        if(pos[0] > 27 || pos[0] < 0)
            pos[0] = 0;
        return pos;
    }
}