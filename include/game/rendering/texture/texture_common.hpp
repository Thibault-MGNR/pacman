#ifndef __TEXTURE_COMMON__
    #define __TEXTURE_COMMON__
    #include <game/rendering/surface.hpp>
    #include <game/rendering/renderer.hpp>
    #include <memory>
    #include <string>
    #include <array>
    #include <SDL2/SDL.h>

    namespace Game {
        enum class Sprites_read_direction{
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
            const Renderer &renderer;
            std::string path;

            Texture_common_data(const Renderer& rdr) : renderer(rdr){}
        };

        struct Texture_static_data : public Texture_common_data {
            using Texture_common_data::Texture_common_data;

            std::array<int, 2> crop_dimension;
            std::array<int, 2> crop_position;
        };

        struct Texture_animation_data : public Texture_common_data {
            using Texture_common_data::Texture_common_data;
            std::array<int, 2> sprites_sheet_pos;
            std::array<int, 2> sprites_sheet_dim;
            std::array<int, 2> sprites_padding;
            std::array<int, 2> sprites_dim;
            int sprites_number;
            int srites_delay;
            Sprites_read_direction read_dir;
        };

        struct Texture_placement{
            std::array<float, 2> position;
            std::array<float, 2> dimension;
        };

        const SDL_Rect set_rect(const std::array<float, 2> &dim, const std::array<float, 2> &pos);

        const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos);

        template <typename T>
        class Texture_common {
            public:
                Texture_common() = delete;
                Texture_common(T data);
                virtual ~Texture_common();
                T get_data();
                virtual SDL_Texture* get_sdl_texture() = 0;
                virtual SDL_Rect get_cropped_rectangle() = 0;
                virtual const Renderer& get_renderer() = 0;

            protected:
                std::shared_ptr<SDL_Texture> _texture;
                T _data;
        };
        #include <rendering/texture/texture_common.tpp>
    }

#endif