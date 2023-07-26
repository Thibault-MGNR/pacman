#include <game/object/character/playable_player.hpp>
#include <SDL2/SDL.h>
#include <memory>
#include <iostream>

namespace Game{
    Playable_player::Playable_player(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Character(renderer, map, is_diplayable){}

    Playable_player::Playable_player(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable) : Character(renderer, data, map, is_diplayable){}

    void Playable_player::set_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        auto forward = [this](){this->set_movement(Movement::FORWARD);};
        auto backward = [this](){this->set_movement(Movement::BACKWARD);};
        auto right = [this](){this->set_movement(Movement::RIGHT);};
        auto left = [this](){this->set_movement(Movement::LEFT);};

        event_pool.add_event(event->key.keysym.sym, SDLK_UP, forward);
        event_pool.add_event(event->key.keysym.sym, SDLK_DOWN, backward);
        event_pool.add_event(event->key.keysym.sym, SDLK_RIGHT, right);
        event_pool.add_event(event->key.keysym.sym, SDLK_LEFT, left);
    }
}