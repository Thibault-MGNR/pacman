#ifndef __OBJECT__
    #define __OBJECT__

    #include <game/object/character/character.hpp>
    #include <game/object/reward/reward.hpp>
    #include <game/object/widget/widget.hpp>
    #include <game/rendering/texture.hpp>
    #include <string>
    #include <memory>

    namespace Game {
        class Object : public Texture{
            public:
                Object() = delete;
                Object(const Renderer &renderer, const std::string path);
                Object(const Renderer &renderer, const std::string path, bool is_diplayable);
                Object(const Renderer &renderer, const std::string path, Texture_data data);
                Object(const Renderer &renderer, const std::string path, Texture_data data, bool is_diplayable);
                bool is_touching(Object &obj);
                void draw() const override;
            
            private:
                bool _is_displayable;

        };
    }

#endif