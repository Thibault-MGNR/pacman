#include <memory>
#include <game/object/character/pac_man.hpp>
#include <game/rendering/texture/static_texture.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Playable_player(map, is_diplayable){
        Texture_static_data data;
        this->_texture_placement.dimension = {25, 25};
        this->_texture_placement.position = {25, 25};
        data.crop_dimension = {15, 15};
        data.crop_position = {455, 0};
        data.path = "data/spritesheet2.png";

        this->_texture = std::make_unique<Static_texture>(renderer, data);
        this->collisions_set.insert(2);
    }

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }
}