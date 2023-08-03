data_type Texture_common::get_data(){
    return this->_data;
}

bool Texture_common::test_collision(std::shared_ptr<Texture_common_data> data){
    // std::vector<bool> is_overlap;
    // is_overlap.push_back(a.position[0] < b.position[0] + b.dimension[0]);
    // is_overlap.push_back(a.position[0] + a.dimension[0] > b.position[0]);
    // is_overlap.push_back(a.position[1] < b.position[1] + b.dimension[1]);
    // is_overlap.push_back(a.dimension[1] + a.position[1] > b.position[1]);

    // if(is_overlap == std::vector<bool>{true, true, true, true})
    //     return true;

    return false;
}