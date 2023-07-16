#ifndef __EVENTS__
    #define __EVENTS__
    #include <functional>
    #include <memory>
    #include <SDL2/SDL.h>

    namespace Game {
        class Events {
            public:
                Events(std::shared_ptr<int> event, int flag, std::function<void()> func);
                Events(const Events& other);
                int get_event() const noexcept;
                void check_and_execute() const;
            
            private:
                std::shared_ptr<int> _event;
                int _flag;
                std::function<void()> _func;
        };
    }

#endif