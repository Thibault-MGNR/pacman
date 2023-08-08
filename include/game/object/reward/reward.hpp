#ifndef __REWARD__
    #define __REWARD__
    #include <game/object/object.hpp>
    #include <memory>

    namespace Game{
        class Reward : public Object{
            public:
                using Object::Object;
                void draw_reward(int x_pm, int y_pm);
            
            protected:
                int _reward_id = -1;
        };
    }

#endif