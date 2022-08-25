#include <iostream>
#include "kbd.h"
void kbd(double kbd_buffer[]){
    for(size_t i=0;i<8;++i){
        std::cin>>kbd_buffer[i];
    }

}
