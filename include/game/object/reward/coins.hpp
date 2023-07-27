#ifndef __COINS__
    #define __COINS__
    #include <game/object/reward/reward.hpp>

    namespace Game {
        class Coins : public Reward {
            public:
                Coins() = delete;
                Coins(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
        };
    }

#endif