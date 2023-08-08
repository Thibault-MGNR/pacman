#ifndef __MAP__
    #define __MAP__
    #include <array>
    #include <memory>
    #include <game/rendering/texture/texture_common.hpp>
    #include <game/rendering/renderer.hpp>
    #include <SDL2/SDL.h>

    namespace Game {
        struct Map_sprite{
            SDL_Rect rect;
            int x, y;
        };
        
        class Map{
            public:
                Map() = delete;
                Map(const Renderer &renderer);
                std::array<std::array<int, 28>, 31> get_map();
                void set_map(std::array<std::array<int, 28>, 31> map);
                void draw();
                Map_sprite get_map_sprite_rect(int x, int y);
            
            private:
                std::array<std::array<int, 28>, 31> _map_init;
                std::array<std::array<int, 28>, 31> _map;
                std::unique_ptr<Texture> _texture;
                Texture_placement _texture_placement;
        };
    }

#endif