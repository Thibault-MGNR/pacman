#include <game/events/events.hpp>
#include <memory>
#include <iostream>

namespace Game{

    Events::Events(std::shared_ptr<int> &event, int flag, std::function<void()> func) : _flag(flag), _func(func){
        this->_event = std::move(event);
    }

    Events::Events(const Events &other) : _event(std::move(other._event)), _flag(other._flag), _func(other._func){}

    int Events::get_event() const noexcept{
        return *this->_event;
    }

    void Events::check_and_execute() const{
        std::cout << *this->_event << " : " << this->_flag << std::endl;
        if(*this->_event == this->_flag){
            std::cout << "check" << std::endl;
            this->_func();
        }
    }
}