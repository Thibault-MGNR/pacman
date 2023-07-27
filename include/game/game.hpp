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
    #include <game/object/character/character.hpp>
    #include <game/rendering/fps_manager.hpp>
    #include <game/object/character/pac_man.hpp>
    #include <game/object/reward/coins.hpp>
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
                std::shared_ptr<Map> _map;
                std::shared_ptr<SDL_Event> _events;
                FPS_manager _fps_manager;
                Events_pool _events_pool;
                std::unique_ptr<Pac_man> _pac_man;
                std::unique_ptr<Coins> _coins;
                bool _run;
                void quit();
                void init_window();
                void init_sdl();
                void init_modules();
                void init_pacman();
                void init_coins();
        };
    }

#endif