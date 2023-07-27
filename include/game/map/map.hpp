#ifndef __MAP__
    #define __MAP__
    #include <array>
    #include <game/rendering/texture.hpp>
    #include <game/rendering/renderer.hpp>
    #include <SDL2/SDL.h>

    namespace Game {
        struct Map_sprite{
            SDL_Rect rect;
            int x, y;
        };
        
        class Map : public Texture{
            public:
                Map() = delete;
                Map(const Renderer &renderer);
                std::array<std::array<int, 28>, 31> get_map();
                void set_map(std::array<std::array<int, 28>, 31> map);
                void draw() override;
                Map_sprite get_map_sprite_rect(int x, int y);
            
            private:
                std::array<std::array<int, 28>, 31> _map_init;
                std::array<std::array<int, 28>, 31> _map;
        };
    }

#endif