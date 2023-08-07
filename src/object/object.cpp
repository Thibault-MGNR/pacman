#include <game/game.hpp>
#include <vector>
#include <SDL2/SDL.h>

const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos){
    SDL_Rect rect;
    rect.w = dim[0];
    rect.h = dim[1];
    rect.x = pos[0];
    rect.y = pos[1];

    return rect;
}

namespace Game {
    Object::Object(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer), _is_displayable(is_diplayable), _map(map){}

    Object::Object(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer, data), _is_displayable(is_diplayable), _map(map){}

    bool Object::is_touching(Object &obj){
        return test_collision(obj.get_data());
    }

    void Object::draw() const{
        if(this->_is_displayable)
            _draw();
    }

    void Object::_draw() const{
        const SDL_Rect srcRect = set_rect(this->_data.crop_dimension, this->_data.crop_position);
        const SDL_Rect dstRect = set_rect(this->_data.dimension, this->_data.position);

        if(SDL_RenderCopy(this->_renderer.get_renderer_ptr(), this->_texture.get(), &srcRect, &dstRect) < 0){
            Exit_with_error();
        }
    }

    std::array<int, 2> Object::get_map_pos(){
        std::array<int, 2> pos;
        int half = this->_data.dimension[0] / 2;
        pos[0] = (this->_data.position[0] + half) / 3.125 / 8;
        pos[1] = (this->_data.position[1] + half) / 3.125 / 8;
        return pos;
    }
}