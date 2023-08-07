#ifndef __STATIC_TEXTURE__
    #define __STATIC_TEXTURE__
    #include <game/rendering/texture/texture_common.hpp>

    namespace Game {
        class Static_texture : public Texture_common<Texture_static_data>{
            public:
                Static_texture(Texture_static_data data);
                SDL_Texture* get_sdl_texture() override;
        };
    }

#endif