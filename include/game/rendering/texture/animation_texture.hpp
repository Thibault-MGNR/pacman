#ifndef __ANIMATION_TEXTURE__
    #define __ANIMATION_TEXTURE__
    #include <game/rendering/texture/texture_common.hpp>
    #include <array>

    namespace Game {
        class Animation_texture : public Texture_common<Texture_animation_data>{
            public:
                Animation_texture(Texture_animation_data data);
                SDL_Texture* get_sdl_texture() override;
                SDL_Rect get_cropped_rectangle() override;
                const Renderer& get_renderer() override;
        };
    }

#endif