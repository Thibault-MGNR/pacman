#include <game/object/character/pac_man.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, bool is_diplayable) : Playable_player(renderer, is_diplayable){}

    Pac_man::Pac_man(const Renderer &renderer, Texture_data data, bool is_diplayable) : Playable_player(renderer, data, is_diplayable){}

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }
}