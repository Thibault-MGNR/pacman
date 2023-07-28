#ifndef __PACGUM__
    #define __PACGUM__
    #include <game/object/reward/reward.hpp>

    namespace Game {
        class Pacgum : public Reward {
            public:
                Pacgum() = delete;
                Pacgum(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
        };
    }
#endif