#pragma once
#include <game/object/character/non_playable_player/ghost.hpp>

namespace Game {
    class Clyde : public Ghost{
        public:
            Clyde() = delete;
            Clyde(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
        
        private:
            void _define_idle_texture() override;
            void _define_forward_texture() override;
            void _define_backward_texture() override;
            void _define_right_texture() override;
            void _define_left_texture() override;
    };
}