#include <game/object/character/pac_man.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable): Playable_player(renderer, map, is_diplayable){
        this->_data = {
            {100, 110},
            {22, 22}, // dimension lors de l'affichage à l'ecran
            {15, 15},
            {455, 0},
            "data/spritesheet2.png"
        };
        initialize_texture();
    }

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }
}