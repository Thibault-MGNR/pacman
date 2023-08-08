#pragma once
#include <variant>
#include <memory>
#include <SDL2/SDL.h>
#include <game/rendering/texture/texture_common.hpp>
#include <game/rendering/texture/static_texture.hpp>
#include <game/rendering/texture/animation_texture.hpp>

namespace Game {
    using Texture_data = std::variant<Texture_animation_data, Texture_static_data>;

    class Texture {
        public:
            Texture() = delete;
            Texture(Texture_data data);
            SDL_Rect get_src_rect();
            SDL_Texture* get_sdl_texture();
            const Renderer& get_renderer();

        private:
            std::variant<std::unique_ptr<Static_texture>, std::unique_ptr<Animation_texture>> _texture;
    };
}