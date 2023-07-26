#ifndef __MAP__
    #define __MAP__
    #include <array>
    #include <game/rendering/texture.hpp>
    #include <game/rendering/renderer.hpp>

    namespace Game {
        class Map : public Texture{
            public:
                Map() = delete;
                Map(const Renderer &renderer);
                std::array<std::array<int, 28>, 31> get_map();
                void set_map(std::array<std::array<int, 28>, 31> map);
            
            private:
                std::array<std::array<int, 28>, 31> _map_init;
                std::array<std::array<int, 28>, 31> _map;
        };
    }

#endif