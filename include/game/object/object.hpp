#ifndef __OBJECT__
    #define __OBJECT__

    #include <game/object/character/character.hpp>
    #include <game/object/reward/reward.hpp>
    #include <game/object/widget/widget.hpp>
    #include <SDL2/SDL.h>
    #include <array>
    #include <memory>

    namespace Game {
        struct Texture_data {
            std::array<int, 2> position;
            std::array<int, 2> dimension;
            std::array<int, 2> crop_dimension;
            std::array<int, 2> crop_position;
            std::shared_ptr<SDL_Texture> texture{};
        };

        class Object {
            public:
                Object() = delete;

            
            protected:
                Texture_data texture;

        };
    }

#endif