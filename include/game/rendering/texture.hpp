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
            std::string path;
        };

        class Texture{
            public:
                // Texture();
                Texture(const Renderer &renderer);
                Texture(const Renderer &renderer, Texture_data data);
                virtual void draw();
                void draw_all() const;
                Texture_data get_data();
            
            protected:
                std::shared_ptr<SDL_Texture> _texture;
                Texture_data _data;
                const Renderer &_renderer;
                void initialize_texture();
                void _draw() const;
                bool test_collision(const Texture_data a, const Texture_data b);
                bool test_collision(std::shared_ptr<Texture> a);
                bool test_collision(const Texture_data a);
                bool test_collision(const SDL_Rect a);
            
            private:
                const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos) const;
        };
    }

#endif