#ifndef __MAP__
    #define __MAP__
    #include <array>
    #include <game/rendering/texture.hpp>
    #include <game/rendering/renderer.hpp>

    namespace Game {
        class Map : public Texture{
            public:
                Map() = delete;
                Map(std::shared_ptr<Renderer> renderer);

                std::array<std::array<int, 21>, 27> get_map();
                void set_map(std::array<std::array<int, 21>, 27> map);
            
            private:
                std::array<std::array<int, 21>, 27> _map_init;
                std::array<std::array<int, 21>, 27> _map;
                Texture _texture;
        };
    }

#endif