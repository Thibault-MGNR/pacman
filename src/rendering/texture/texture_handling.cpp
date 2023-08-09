#include <array>
#include <algorithm>
#include <game/rendering/texture/texture_handling.hpp>

namespace Game {
    bool operator==(const Texture_static_data& p1, const Texture_static_data& p2){
        std::array<bool, 3> tests;
        tests[0] = p1.path == p2.path;
        tests[1] = p1.crop_dimension == p2.crop_dimension;
        tests[2] = p1.crop_position == p2.crop_position;

        std::array<bool, 3> expected_value;
        std::fill(expected_value.begin(), expected_value.end(), true);

        return tests == expected_value;
    }

    bool operator!=(const Texture_static_data& p1, const Texture_static_data& p2){
        return !(p1 == p2);
    }

    bool operator==(const Texture_animation_data& p1, const Texture_animation_data& p2){
        std::array<bool, 7> tests;
        tests[0] = p1.path == p2.path;
        tests[1] = p1.read_dir == p2.read_dir;
        tests[2] = p1.sprites_dim == p2.sprites_dim;
        tests[3] = p1.sprites_number == p2.sprites_number;
        tests[4] = p1.sprites_sheet_dim == p2.sprites_sheet_dim;
        tests[5] = p1.sprites_sheet_pos == p2.sprites_sheet_pos;
        tests[6] = p1.srites_delay == p2.srites_delay;

        std::array<bool, 7> expected_value;
        std::fill(expected_value.begin(), expected_value.end(), true);

        return tests == expected_value;
    }

    bool operator!=(const Texture_animation_data& p1, const Texture_animation_data& p2){
        return !(p1 == p2);
    }
}