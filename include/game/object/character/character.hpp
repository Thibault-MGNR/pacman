#ifndef __CHARACTER__
    #define __CHARACTER__
    #include <set>
    #include <array>
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
                using Object::Object;
                void set_movement(const Movement mvt) noexcept;
                void draw() override;
            
            protected:
                std::set<int> collisions_set{1};
                bool _has_motion_responsive_texture;
                std::array<Texture_animation_data, 5> _motion_responsive_texture_animation_data;
                std::array<Texture_static_data, 5> _motion_responsive_texture_static_data;
                void _update();

            private:
                void _update_static_texture();
                void _update_animated_texture();
                bool map_collision(Movement mov);
                Movement _next_movement = Movement::IDLE;
                Movement _desired_movement = Movement::IDLE;
                const float speed = 2;
                bool check_map_collision_forward(int x_m, int y_m);
                bool check_map_collision_backward(int x_m, int y_m);
                bool check_map_collision_right(int x_m, int y_m);
                bool check_map_collision_left(int x_m, int y_m);
                bool check_map_sprites_collisions(std::array<Map_sprite, 3> sprites);
                void move(Movement movement);
                void process_next_movement_with_collision(std::array<float, 2> last_pos);
        };
    }
#endif