#ifndef __RENDERER__
    #define __RENDERER__
    #include <game/rendering/window.hpp>
    #include <SDL2/SDL.h>
    #include <memory>

    namespace Game {
        class Renderer {
            public:
                Renderer() = delete;
                Renderer(Window &window);
                Renderer operator=(const Renderer &renderer) const;
                std::shared_ptr<SDL_Renderer> get_renderer() const;
                SDL_Renderer *get_renderer_ptr() const;
            
            private:
                Window &_window;
                std::shared_ptr<SDL_Renderer> _renderer;
        };
    }

#endif