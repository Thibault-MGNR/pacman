#ifndef __OBJECT__
    #define __OBJECT__
    #include <game/object/reward/reward.hpp>
    #include <game/object/widget/widget.hpp>
    #include <game/rendering/texture.hpp>
    #include <game/map/map.hpp>
    #include <string>
    #include <memory>

    namespace Game {
        class Object : public Texture{
            public:
                Object() = delete;
                Object(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
                Object(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);
                bool is_touching(Object &obj);
                void draw() override;
            
            protected:
                bool _is_displayable;
                std::shared_ptr<Map> _map;

        };
    }

#endif