#pragma once
#include <game/object/character/non_playable_player/non_playable_player.hpp>

namespace Game {
    class Ghost : public Non_playable_player {
        public:
            Ghost() = delete;
            Ghost(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable);
        
        protected:
            virtual void _define_idle_texture() = 0;
            virtual void _define_forward_texture() = 0;
            virtual void _define_backward_texture() = 0;
            virtual void _define_right_texture() = 0;
            virtual void _define_left_texture() = 0;
            void _define_texture();
        
        private:
            void _define_common_texture_data();
    };
}