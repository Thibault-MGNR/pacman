#include <game/events/events.hpp>
#include <memory>
#include <iostream>

namespace Game{

    Events::Events(std::shared_ptr<uint32_t> event, uint32_t flag, std::function<void()> func) : _flag(flag), _func(func){
        this->_event = std::move(event);
    }

    Events::Events(const Events &other) : _event(other._event), _flag(other._flag), _func(other._func){}

    int Events::get_event() const noexcept{
        return *this->_event;
    }

    void Events::check_and_execute() const{
        if(*this->_event == this->_flag){
            this->_func();
        }
    }
}