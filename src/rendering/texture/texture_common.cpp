#include <game/rendering/texture/texture_common.hpp>

namespace Game {
    const SDL_Rect set_rect(const std::array<float, 2> &dim, const std::array<float, 2> &pos){
        SDL_Rect rect;
        rect.w = static_cast<int>(dim[0]);
        rect.h = static_cast<int>(dim[1]);
        rect.x = static_cast<int>(pos[0]);
        rect.y = static_cast<int>(pos[1]);

        return rect;
    }

    const SDL_Rect set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos){
        SDL_Rect rect;
        rect.w = dim[0];
        rect.h = dim[1];
        rect.x = pos[0];
        rect.y = pos[1];

        return rect;
    }
}