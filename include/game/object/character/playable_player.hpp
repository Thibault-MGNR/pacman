#ifndef __PLAYABLE_PLAYER__
    #define __PLAYABLE_PLAYER__
    #include <game/object/character/character.hpp>
    #include <game/events/events_pool.hpp>

    namespace Game{
        class Playable_player : public Character{
            public:
                Playable_player() = delete;
                Playable_player(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
                Playable_player(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);
            
            protected:
                void set_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event);

        };
    }
#endif