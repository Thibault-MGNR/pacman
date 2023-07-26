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
        };
    }
#endif