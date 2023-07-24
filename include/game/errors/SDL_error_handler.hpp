#ifndef __SDL_ERROR_HANDLER__
    #define __SDL_ERROR_HANDLER__
    #include <functional>

    namespace Game {
        class Decorator{
            public:
                template <typename Fnc, typename... Args>
                static constexpr auto decod(Fnc&& f, Args&&... args);
        };

        template <typename Deco, typename Fnc, typename... Args>
        static constexpr auto Check_SDL_errors(Fnc&& f, Args&&... args);

        template<typename Fnc, typename... Args>
        static constexpr auto Check(Fnc f, Args&&... args);

        void Exit_with_error();
        
    }

#include <error/SDL_error_handle.tpp>

#endif