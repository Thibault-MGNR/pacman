#include <game/game.hpp>
#include <vector>

namespace Game {
    Object::Object(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer), _is_displayable(is_diplayable), _map(map){}

    Object::Object(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Texture(renderer, data), _is_displayable(is_diplayable), _map(map){}

    bool Object::is_touching(Object &obj){
        std::vector<bool> is_overlap;
        is_overlap.push_back(this->_data.position[0] < obj._data.position[0] + obj._data.dimension[0]);
        is_overlap.push_back(this->_data.position[0] + this->_data.dimension[0] > obj._data.position[0]);
        is_overlap.push_back(this->_data.position[1] < obj._data.position[1] + obj._data.dimension[1]);
        is_overlap.push_back(this->_data.dimension[1] + this->_data.position[1] > obj._data.position[1]);

        if(is_overlap == std::vector<bool>{true, true, true, true})
            return true;

        return false;
    }

    void Object::draw(){
        if(this->_is_displayable)
            _draw();
    }
}