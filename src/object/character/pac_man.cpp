#include <memory>
#include <game/object/character/pac_man.hpp>
#include <game/rendering/texture/static_texture.hpp>
#include <game/rendering/texture/animation_texture.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Playable_player(map, is_diplayable){
        Texture_animation_data data;
        this->_texture_placement.dimension = {25, 25};
        this->_texture_placement.position = {25, 25};
        data.sprites_dim = {16, 16};
        data.sprites_sheet_pos = {455, 0};
        data.sprites_sheet_dim = {32, 16};
        data.srites_delay = 200;
        data.sprites_number = 2;
        data.path = "data/spritesheet2.png";

        this->_texture = std::make_unique<Animation_texture>(renderer, data);
        this->collisions_set.insert(2);
    }

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }
}