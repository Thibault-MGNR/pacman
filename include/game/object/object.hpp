#ifndef __OBJECT__
    #define __OBJECT__
    #include <game/rendering/texture.hpp>
    #include <game/map/map.hpp>
    #include <string>
    #include <array>
    #include <memory>

    namespace Game {
        class Object : public Texture{
            public:
                Object() = delete;
                Object(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
                Object(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);
                bool is_touching(Object &obj);
                void draw() override;
                std::array<int, 2> get_map_pos();
            
            protected:
                bool _is_displayable;
                std::shared_ptr<Map> _map;

        };
    }

#endif