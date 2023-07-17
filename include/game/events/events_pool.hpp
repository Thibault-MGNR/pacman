#ifndef __EVENTS_POOL__
    #define __EVENTS_POOL__
    #include <game/events/events.hpp>
    #include <vector>
    #include <functional>
    #include <SDL2/SDL.h>

    namespace Game {
        class Events_pool {
            public:
                Events_pool();
                void add_event(const uint32_t &event, uint32_t flag, std::function<void()> func);
                void check_events();
            private:
                std::vector<std::shared_ptr<Events>> _pool;
        };
    }

#endif