#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace Game {
    template <typename Fnc, typename... Args>
    constexpr auto Decorator::decod(Fnc&& f, Args&&... args){
        auto value = f(args...);
        if(!value){
            Exit_with_error();
        }

        return value;
    }

    template <typename Deco, typename Fnc, typename... Args>
    constexpr auto Check_SDL_errors(Fnc &&f, Args &&...args)
    {
        return Deco::template decod<Fnc, Args...>(std::forward<Fnc>(f), std::forward<Args>(args)...);
    }

    template<typename Fnc, typename... Args>
    static constexpr auto Check(Fnc f, Args&&... args){
        return Check_SDL_errors<Decorator, Fnc, Args...>(std::forward<Fnc>(f), std::forward<Args>(args)...);
    }

}