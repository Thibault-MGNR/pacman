#pragma once
#include <game/object/character/non_playable_player/ghost.hpp>

namespace Game {
    class Pinky : public Ghost{
        public:
            Pinky() = delete;
            Pinky(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
        
        private:
            void _define_idle_texture();
            void _define_forward_texture();
            void _define_backward_texture();
            void _define_right_texture();
            void _define_left_texture();
            void _define_texture();
            void _define_common_texture_data();
    };
}