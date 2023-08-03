#include <game/rendering/texture/texture_utils.hpp>

namespace Game{
    const SDL_Rect Texture_utils::set_rect(const std::array<int, 2> &dim, const std::array<int, 2> &pos) const{
        SDL_Rect rect;
        rect.w = dim[0];
        rect.h = dim[1];
        rect.x = pos[0];
        rect.y = pos[1];

        return rect;
    }
}