#ifndef __CHARACTER__
    #define __CHARACTER__
    #include <game/object/object.hpp>

    namespace Game {
        enum class Movement{
            IDLE,
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };

        class Character : public Object{
            public:
                Character() = delete;
                Character(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
                Character(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);

                void set_movement(const Movement mvt) noexcept;
                void draw() override;

            private:
                bool map_collision();
                Movement _next_movement;
                const int speed = 2;
                bool check_map_collision_forward(int x_m, int y_m);
                bool check_map_collision_backward(int x_m, int y_m);
                bool check_map_collision_right(int x_m, int y_m);
                bool check_map_collision_left(int x_m, int y_m);
                bool check_map_sprites_collisions(std::array<Map_sprite, 3> sprites);
        };
    }
#endif