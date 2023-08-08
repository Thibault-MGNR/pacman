#ifndef __STATIC_TEXTURE__
    #define __STATIC_TEXTURE__
    #include <game/rendering/texture/texture_common.hpp>

    namespace Game {
        class Static_texture : public Texture{
            public:
                Static_texture(const Renderer &renderer, Texture_static_data data);
                SDL_Texture* get_sdl_texture() override;
                SDL_Rect get_src_rect() override;
        };
    }

#endif