#ifndef __ANIMATION_TEXTURE__
    #define __ANIMATION_TEXTURE__
    #include <array>

    namespace Game {
        enum class Sprites_read_direction{
            TOP_RIGHT_TO_BOTTOM_LEFT,
            TOP_LEFT_TO_BOTTOM_RIGHT,
            BOTTOM_RIGHT_TO_TOP_LEFT,
            BOTTOM_LEFT_TO_TOP_RIGHT,
            LEFT_TO_RIGHT = TOP_LEFT_TO_BOTTOM_RIGHT,
            RIGHT_TO_LEFT = TOP_RIGHT_TO_BOTTOM_LEFT,
            TOP_TO_BOTTOM = TOP_LEFT_TO_BOTTOM_RIGHT,
            BOTTOM_TO_TOP = BOTTOM_LEFT_TO_TOP_RIGHT
        };

        struct Animation_data {
            std::array<int, 2> sprites_sheet_pos;
            std::array<int, 2> sprites_sheet_dim;
            std::array<int, 2> sprites_padding;
            std::array<int, 2> sprites_dim;
            int sprites_nember;
            int srites_delay;
            Sprites_read_direction read_dir;
        };

        class Animation_texture{

        };
    }

#endif