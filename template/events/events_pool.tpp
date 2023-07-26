template<typename T>
void Events_pool::add_event(const T &event, int flag, std::function<void()> func){
    if (!std::is_integral<T>::value || sizeof(T) > sizeof(int)){
        exit(EXIT_FAILURE); 
    }

    this->_pool.push_back(std::make_shared<Events>(reinterpret_cast<const int&>(event), flag, func));
}