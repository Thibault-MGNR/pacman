#ifndef __WINDOW__
    #define __WINDOW__
    #include <SDL2/SDL.h>
    #include <string>
    #include <array>
    #include <memory>

    namespace Game {
        struct Window_parameter {
            std::string title;
            std::array<int, 2> position;
            std::array<int, 2> size;
        };

        class Window {
            public:
                Window() = delete;
                Window(const Window_parameter param);
                std::shared_ptr<SDL_Window> get_window() const noexcept;

            
            private:
                Window_parameter _param;
                std::shared_ptr<SDL_Window> _window;
        };
    }

#endif