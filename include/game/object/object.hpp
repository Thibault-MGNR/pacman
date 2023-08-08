#ifndef __OBJECT__
    #define __OBJECT__
    #include <game/rendering/texture/texture.hpp>
    #include <game/map/map.hpp>
    #include <string>
    #include <array>
    #include <memory>

    namespace Game {
        class Object{
            public:
                Object() = delete;
                Object(std::shared_ptr<Map> map, bool is_diplayable = true);
                bool test_collision(Object &obj);
                bool test_collision(SDL_Rect rect);
                std::array<int, 2> get_map_pos();
                virtual void draw();
            
            protected:
                bool _is_displayable;
                std::shared_ptr<Map> _map;
                std::unique_ptr<Texture> _texture;
                void _draw() const;
                Texture_placement _texture_placement;
        };
    }

#endif