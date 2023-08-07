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
                Object(Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);
                bool is_touching(Object &obj);
                std::array<int, 2> get_map_pos();
                void draw() const;
            
            protected:
                bool _is_displayable;
                std::shared_ptr<Map> _map;
                void _draw() const;

        };
    }

#endif