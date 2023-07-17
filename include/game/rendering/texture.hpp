#ifndef __TEXTURE__
    #define __TEXTURE__
    #include <game/rendering/surface.hpp>
    #include <game/rendering/renderer.hpp>
    #include <memory>
    #include <string>
    #include <array>
    #include <SDL2/SDL.h>

    namespace Game {
        struct Texture_data {
            std::array<int, 2> position;
            std::array<int, 2> dimension;
            std::array<int, 2> crop_dimension;
            std::array<int, 2> crop_position;
        };

        class Texture{
            public:
                // Texture();
                Texture(const Renderer &renderer);
                Texture(const Renderer &renderer, std::string path);
                Texture(const Renderer &renderer, std::string path, Texture_data data);
                void draw() const;
                void draw_all() const;
            
            protected:
                std::shared_ptr<SDL_Texture> _texture;
                std::string _path;
                Texture_data _data;
                const Renderer &_renderer;
                void initialize();
        };
    }

#endif