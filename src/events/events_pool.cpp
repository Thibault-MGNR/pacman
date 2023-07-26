#include <game/events/events_pool.hpp>
#include <iterator>
#include <iostream>

namespace Game {
    Events_pool::Events_pool(){}

    void Events_pool::check_events(){
        auto event{std::begin(this->_pool)};

        while(event != std::end(this->_pool)){
            event->get()->check_and_execute();
            event++;
        }
    }
}