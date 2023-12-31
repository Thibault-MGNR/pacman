#ifndef __PAC_MAN__
    #define __PAC_MAN__
    #include <game/object/character/playable_player.hpp>

    namespace Game{
        class Pac_man : public Playable_player{
            public:
                Pac_man() = delete;
                Pac_man(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);

                void init_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event);
        };
    }

#endif