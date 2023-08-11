#include <memory>
#include <game/object/character/playable_player/pac_man.hpp>
#include <game/rendering/texture/static_texture.hpp>
#include <game/rendering/texture/animation_texture.hpp>

namespace Game {
    Pac_man::Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable) : Playable_player(map, is_diplayable){
        Texture_animation_data data;
        this->_texture_placement.dimension = {25, 25};
        this->_texture_placement.position = {337, 425};
        data.path = "data/spritesheet2.png";
        data.srites_delay = 80;
        data.sprites_number = 1;
        data.sprites_dim = {16, 16};
        data.sprites_sheet_dim = {16, 16};
        data.sprites_sheet_pos = {488, 0};
        this->_texture = std::make_unique<Animation_texture>(renderer, data);

        _define_texture();
        this->_has_motion_responsive_texture = true;
        this->collisions_set.insert(2);
        _update();
    }

    void Pac_man::init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event){
        set_events(event_pool, event);
    }

    void Pac_man::_define_idle_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::IDLE)]; 
        data.sprites_sheet_pos = {488, 0};
        data.sprites_sheet_dim = {16, 16};
        data.sprites_number = 1;
        data.srites_delay = 2000;
    }

    void Pac_man::_define_forward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::FORWARD)]; 
        data.sprites_sheet_pos = {456, 32};
    }

    void Pac_man::_define_backward_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::BACKWARD)]; 
        data.sprites_sheet_pos = {456, 48};
    }

    void Pac_man::_define_right_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::RIGHT)]; 
        data.sprites_sheet_pos = {456, 0};
    }

    void Pac_man::_define_left_texture(){
        Texture_animation_data& data = this->_motion_responsive_texture_animation_data[static_cast<int>(Movement::LEFT)]; 
        data.sprites_sheet_pos = {456, 16};
    }

    void Pac_man::_define_common_texture_data(){
        for(auto& element : this->_motion_responsive_texture_animation_data){
            element.path = "data/spritesheet2.png";
            element.srites_delay = 80;
            element.sprites_number = 2;
            element.sprites_dim = {16, 16};
            element.sprites_sheet_dim = {32, 16};
        }
    }

    void Pac_man::_define_texture(){
        _define_common_texture_data();
        _define_forward_texture();
        _define_backward_texture();
        _define_left_texture();
        _define_right_texture();
        _define_idle_texture();
    }

}