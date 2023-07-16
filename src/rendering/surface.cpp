#include <game/rendering/surface.hpp>

namespace Game {
    Surface::Surface(const std::string path) : _path(path){
        this->_surface = std::shared_ptr<SDL_Surface>{IMG_Load(this->_path.c_str()), SDL_FreeSurface};
    }

    std::shared_ptr<SDL_Surface> Surface::get_surface() const noexcept {
        return this->_surface;
    }
}