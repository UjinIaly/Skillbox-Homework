#include <iostream>
#include <fstream>
#include "disk.h"

void disk( double ram_buffer[],double load_buffer[]){
    std::string action;
    std::cout<<"load or save?"<<std::endl;
    std::cin>>action;
    std::ifstream data_read;
    data_read.open("/home/iwaly/Skillbox-Homework/hw_25.2/data.txt",std::ios::app);
    std::ofstream data_write;
    data_write.open("/home/iwaly/Skillbox-Homework/hw_25.2/data.txt",std::ios::app);
    size_t i=0;

    double temp[8];

    if(action == "load"){
        while(!data_read.eof()){
            data_read>>load_buffer[i];
            ++i;
        }
        data_read.close();
    }
    else if(action == "save"){
        for(i=0;i<8;++i){
            data_write<<ram_buffer[i]<<std::endl;
        }
        data_write.close();
    }
}