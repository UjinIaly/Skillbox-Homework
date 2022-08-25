#include <iostream>

void ram(double kbd_buffer[],double ram_buffer[],double load_buffer[]){
    std::cout<<"write or read?"<<std::endl;
    std::string action;
    std::cin>>action;

    if(action == "write"){
        for(size_t i=0;i<8;++i){
            ram_buffer[i]=kbd_buffer[i];
        }
    }
    else if(action == "read"){
        for(size_t i = 0;i<8;++i) {
            ram_buffer[i] = load_buffer[i];
        }
    }
}