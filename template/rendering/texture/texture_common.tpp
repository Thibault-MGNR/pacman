Texture_common::Texture_common(data_type data) : _data(data){}

virtual Texture_common::~Texture_common(){}

data_type Texture_common::get_data(){
    return this->_data;
}