#include <game/events/events.hpp>
#include <memory>
#include <iostream>

namespace Game{
    Events::Events(const uint32_t &event, const uint32_t flag, std::function<void()> func) : 
        _event(event), 
        _flag(flag), 
        _func(func){}

    Events::Events(const Events &other) : _event(other._event), _flag(other._flag), _func(other._func){}

    int Events::get_event() const noexcept{
        return this->_event;
    }

    void Events::check_and_execute() const{
        if(this->_event == this->_flag){
            this->_func();
        }
    }
}