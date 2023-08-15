#pragma once
#include <stack>
#include <tuple>
#include <game/object/character/character.hpp>
#include <game/algorithm_suite/a_star.hpp>

namespace Game {
    class Non_playable_player : public Character {
        public:
            Non_playable_player() = delete;
            Non_playable_player(std::shared_ptr<Map> map, bool is_diplayable = true);
            void draw_path(int x, int y);
            void update_movement() override;
        
        protected:
            Path_finding _path_finder;
            std::stack<std::pair<int, int>> _path;
        
        private:
            void diag_mov(Movement a, Movement b);
    };
}