#ifndef __TEXTURE_COMMON__
    #define __TEXTURE_COMMON__
    #include <game/rendering/surface.hpp>
    #include <game/rendering/renderer.hpp>
    #include <memory>
    #include <string>
    #include <array>
    #include <SDL2/SDL.h>

    namespace Game {
        enum class Sprites_read_direction_{
            TOP_RIGHT_TO_BOTTOM_LEFT,
            TOP_LEFT_TO_BOTTOM_RIGHT,
            BOTTOM_RIGHT_TO_TOP_LEFT,
            BOTTOM_LEFT_TO_TOP_RIGHT,
            LEFT_TO_RIGHT = TOP_LEFT_TO_BOTTOM_RIGHT,
            RIGHT_TO_LEFT = TOP_RIGHT_TO_BOTTOM_LEFT,
            TOP_TO_BOTTOM = TOP_LEFT_TO_BOTTOM_RIGHT,
            BOTTOM_TO_TOP = BOTTOM_LEFT_TO_TOP_RIGHT
        };

        struct Texture_common_data {
            Renderer &renderer;
            std::array<int, 2> position;
            std::array<int, 2> dimension;
            std::string path;
        };

        struct Texture_static_data : public Texture_common_data {
            std::array<int, 2> crop_dimension;
            std::array<int, 2> crop_position;
        };

        struct Texture_animation_data : public Texture_common_data {
            std::array<int, 2> sprites_sheet_pos;
            std::array<int, 2> sprites_sheet_dim;
            std::array<int, 2> sprites_padding;
            std::array<int, 2> sprites_dim;
            int sprites_number;
            int srites_delay;
            Sprites_read_direction_ read_dir;
        };

        template <typename data_type>
        class Texture_common {
            public:
                Texture_common() = delete;
                Texture_common(data_type data);
                virtual ~Texture_common() = 0;
                virtual void draw() = 0;
                data_type get_data();

            protected:
                virtual void _draw(data_type data) = 0;
                data_type _data;
                bool test_collision(std::shared_ptr<Texture_common_data> data);
        };
        
        #include <rendering/texture/texture_common.tpp>
    }

#endif