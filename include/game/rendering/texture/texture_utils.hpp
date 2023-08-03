#ifndef __TEXTURE_UTILS__
    #define __TEXTURE_UTILS__
    #include <SDL2/SDL.h>
    #include <array>

    namespace Game {
        class Texture_utils{
            public:
                static const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos) const;
        };
    }

#endif