#ifndef __GAME__
    #define __GAME__
    #include <game/object/object.hpp>
    #include <game/audio/audio.hpp>
    #include <game/rendering/renderer.hpp>
    #include <game/rendering/surface.hpp>
    #include <game/rendering/window.hpp>
    #include <game/rendering/texture.hpp>
    #include <game/events/events_pool.hpp>
    #include <game/map/map.hpp>
    #include <SDL2/SDL.h>
    #include <memory>

    namespace Game {

        class Game {
            public:
                Game();
                ~Game();
                void run();
                
            private:
                std::unique_ptr<Window> _window;
                std::unique_ptr<Renderer> _renderer;
                std::unique_ptr<Map> _map;
                std::shared_ptr<SDL_Event> _events;
                Events_pool _events_pool;
                bool _run;
                void quit();
        };
    }

#endif