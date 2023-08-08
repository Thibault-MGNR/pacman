template <typename T>
Texture_common<T>::Texture_common(T data) : _data(data){}

template <typename T>
Texture_common<T>::~Texture_common(){}

template <typename T>
T Texture_common<T>::get_data(){
    return this->_data;
}