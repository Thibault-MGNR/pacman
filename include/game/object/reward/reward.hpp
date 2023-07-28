#ifndef __REWARD__
    #define __REWARD__
    #include <game/object/object.hpp>
    #include <memory>

    namespace Game{
        class Reward : public Object{
            public:
                Reward() = delete;
                Reward(const Renderer &renderer, std::shared_ptr<Map> map, bool is_diplayable = true);
                Reward(const Renderer &renderer, Texture_data data, std::shared_ptr<Map> map, bool is_diplayable = true);
                void draw_reward(int x_pm, int y_pm);
            
            protected:
                int _reward_id;
        };
    }

#endif