#ifndef __FPS_MANAGER__
    #define __FPS_MANAGER__

    namespace Game {
        class FPS_manager {
            public:
                FPS_manager();
                FPS_manager(const int max_FPS);

                void manage();
                void set_max_FPS(const int max);
            
            private:
                float _last_ticks;
                float _max_FPS;
                float _timeout;
        };
    }
#endif