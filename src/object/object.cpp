#include <game/game.hpp>
#include <vector>

namespace Game {
    Object::Object(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer), _is_displayable(is_diplayable), _map(map){}

    Object::Object(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer, data), _is_displayable(is_diplayable), _map(map){}

    bool Object::is_touching(Object &obj){
        return test_collision(obj.get_data());
    }

    void Object::draw(){
        if(this->_is_displayable)
            _draw();
    }

    std::array<int, 2> Object::get_map_pos(){
        std::array<int, 2> pos;
        int half = this->_data.dimension[0] / 2;
        pos[0] = (this->_data.position[0] + half) / 3.125 / 8;
        pos[1] = (this->_data.position[1] + half) / 3.125 / 8;
        return pos;
    }
}