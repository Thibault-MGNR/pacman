#include <game/events/events_pool.hpp>
#include <iterator>

Game::Events_pool::Events_pool(){}

void Game::Events_pool::add_event(std::shared_ptr<int> &event, int flag, std::function<void()> func){
    Game::Events new_event{event, flag, func};
    this->_pool.push_back(std::unique_ptr<Events>(new_event));
}

void Game::Events_pool::check_events(){
    auto event{std::begin(this->_pool)};

    while(event != std::end(this->_pool)){
        event->get()->check_and_execute();
        event++;
    }
}