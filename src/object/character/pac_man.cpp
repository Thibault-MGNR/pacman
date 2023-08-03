#include <game/object/character/pac_man.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable): Playable_player(renderer, map, is_diplayable){
        this->_data = {
            {25, 25},
            {25, 25},
            {15, 15},
            {455, 0},
            "data/spritesheet2.png"
        };
        initialize_texture();
        this->collisions_set.insert(2);
    }

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }
}