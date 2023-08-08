#ifndef __CHARACTER__
    #define __CHARACTER__
    #include <game/object/object.hpp>
    #include <set>

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

            private:
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