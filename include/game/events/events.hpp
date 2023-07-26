#ifndef __EVENTS__
    #define __EVENTS__
    #include <functional>
    #include <memory>
    #include <SDL2/SDL.h>

    namespace Game {
        class Events {
            public:
                Events(const int &event, const int flag, std::function<void()> func);
                Events(const Events& other);
                int get_event() const noexcept;
                void check_and_execute() const;
            
            private:
                const int &_event;
                const int _flag;
                std::function<void()> _func;
        };
    }

#endif