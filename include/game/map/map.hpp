#ifndef __MAP__
    #define __MAP__
    #include <array>
    #include <game/rendering/texture.hpp>
    #include <game/rendering/renderer.hpp>

    namespace Game {
        class Map {
            public:
                Map() = delete;
                Map(std::shared_ptr<Renderer> renderer);
                void draw() const;
            
            private:
                std::array<std::array<int, 21>, 27> _map_init;
                Texture _texture;
        };
    }

#endif