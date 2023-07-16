#include <game/events/events_pool.hpp>
#include <iterator>

namespace Game {
    Events_pool::Events_pool(){}

    void Events_pool::add_event(std::shared_ptr<uint32_t> event, uint32_t flag, std::function<void()> func){
        this->_pool.push_back(std::make_shared<Events>(event, flag, func));
    }

    void Events_pool::check_events(){
        auto event{std::begin(this->_pool)};

        while(event != std::end(this->_pool)){
            event->get()->check_and_execute();
            event++;
        }
    }
}