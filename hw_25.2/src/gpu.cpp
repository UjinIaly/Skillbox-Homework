#include <iostream>
#include "gpu.h"
void gpu(double numbers[]){
    for(size_t i=0;i<8;++i){
        std::cout<<numbers[i]<<" "<<std::endl;
    }
}