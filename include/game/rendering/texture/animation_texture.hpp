#ifndef __ANIMATION_TEXTURE__
    #define __ANIMATION_TEXTURE__
    #include <game/rendering/texture/texture_common.hpp>
    #include <array>

    namespace Game {
        class Animation_texture : public Texture{
            public:
                Animation_texture(const Renderer &renderer,  Texture_animation_data data);
                SDL_Texture* get_sdl_texture() override;
                SDL_Rect get_src_rect() override;
                void update_texture() override;
                void update_frame();

            private:
                int _current_number_frame;
                int _frame_tick;
                Texture_placement _current_frame;
                std::array<int, 2> _sprites_sheet_grid;
                void _update_frame_TRBL();
                void _update_frame_TLBR();
                void _update_frame_BRTL();
                void _update_frame_BLTR();
        };
    }

#endif