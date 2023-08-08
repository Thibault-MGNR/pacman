#pragma once

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

    struct Texture_common_data {
        std::string path;
    };

    struct Texture_static_data : public Texture_common_data {
        using Texture_common_data::Texture_common_data;

        std::array<int, 2> crop_dimension = {0, 0};
        std::array<int, 2> crop_position = {0, 0};
    };

    struct Texture_animation_data : public Texture_common_data {
        using Texture_common_data::Texture_common_data;
        std::array<int, 2> sprites_sheet_pos = {0, 0};
        std::array<int, 2> sprites_sheet_dim = {0, 0};
        std::array<int, 2> sprites_padding = {0, 0};
        std::array<int, 2> sprites_dim = {0, 0};
        int sprites_number = 0;
        int srites_delay = 50;
        Sprites_read_direction read_dir = Sprites_read_direction::TOP_LEFT_TO_BOTTOM_RIGHT;
    };

    struct Texture_placement{
        std::array<float, 2> position = {0, 0};
        std::array<float, 2> dimension = {0, 0};
    };
}