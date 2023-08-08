#ifndef __PLAYABLE_PLAYER__
    #define __PLAYABLE_PLAYER__
    #include <game/object/character/character.hpp>
    #include <game/events/events_pool.hpp>

    namespace Game{
        class Playable_player : public Character{
            public:
                using Character::Character;
            
            protected:
                void set_events(Events_pool &event_pool, std::shared_ptr<SDL_Event> event);

        };
    }
#endif