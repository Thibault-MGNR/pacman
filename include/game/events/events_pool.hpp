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
                void check_events();

                template<typename T>
                void add_event(const T &event, int flag, std::function<void()> func);

            private:
                std::vector<std::shared_ptr<Events>> _pool;
        };

        #include <events/events_pool.tpp>
    }

#endif