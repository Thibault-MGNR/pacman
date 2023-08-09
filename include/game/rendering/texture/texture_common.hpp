#ifndef __TEXTURE_COMMON__
    #define __TEXTURE_COMMON__
    #include <array>
    #include <memory>
    #include <string>
    #include <SDL2/SDL.h>
    #include <game/rendering/surface.hpp>
    #include <game/rendering/renderer.hpp>
    #include <game/rendering/texture/texture_handling.hpp>

    namespace Game {
        const SDL_Rect set_rect(const std::array<float, 2> &dim, const std::array<float, 2> &pos);

        const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos);

        const Texture_placement set_tp_from_sdl_rect(const SDL_Rect& rect);

        enum class Texture_type {STATIC, ANIMATED};

        class Texture {
            public:
                Texture() = delete;
                Texture(const Renderer &renderer, Texture_animation_data data);
                Texture(const Renderer &renderer, Texture_static_data data);
                virtual ~Texture();
                Texture_animation_data get_animation_data();
                Texture_static_data get_static_data();
                virtual SDL_Texture* get_sdl_texture() = 0;
                virtual SDL_Rect get_src_rect() = 0;
                const Renderer& get_renderer();
                void set_data(Texture_animation_data data);
                void set_data(Texture_static_data data);
                virtual void update_texture();
                Texture_type get_type();

            protected:
                std::shared_ptr<SDL_Texture> _texture;
                const Renderer &_renderer;
            
            private:
                Texture_type _type_of_texture;
                Texture_animation_data _data_animation;
                Texture_static_data _data_static;
        };
    }

#endif