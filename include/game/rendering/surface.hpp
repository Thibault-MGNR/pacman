#ifndef __SURFACE__
    #define __SURFACE__
    #include <string>
    #include <memory>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>

    namespace Game {
        class Surface {
            public:
                Surface() = delete;
                Surface(const std::string path);
                std::shared_ptr<SDL_Surface> get_surface() const noexcept;
            
            private:
                std::string _path;
                std::shared_ptr<SDL_Surface> _surface;
        };
    }

#endif