#include <iostream>
#include "cpu.h"

void cpu(double ram_buffer[]){
    double sum=0;
    for(size_t i=0;i<8;++i){
        sum+=ram_buffer[i];
    }
    std::cout<<sum<<std::endl;
}