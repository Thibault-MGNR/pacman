#include <game/object/character/playable_player.hpp>
#include <SDL2/SDL.h>
#include <memory>

namespace Game{
    Playable_player::Playable_player(const Renderer &renderer, bool is_diplayable) : Character(renderer, is_diplayable){}

    Playable_player::Playable_player(const Renderer &renderer, Texture_data data, bool is_diplayable) : Character(renderer, data, is_diplayable){}

    void Playable_player::move_left(){
        set_movement(Movement::LEFT);
    }

    void Playable_player::move_right(){
        set_movement(Movement::RIGHT);
    }

    void Playable_player::move_forward(){
        set_movement(Movement::FORWARD);
    }

    void Playable_player::move_backward(){
        set_movement(Movement::BACKWARD);
    }

    void Playable_player::set_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        // event_pool.add_event(event->type, SDLK_RIGHT, move_right);
    }
}