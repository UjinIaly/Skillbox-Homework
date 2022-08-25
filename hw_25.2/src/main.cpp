#include <iostream>
#include "kbd.h"
#include "gpu.h"
#include "cpu.h"
#include "disk.h"
#include "ram.h"


int main() {
    std::string command;
    double kbd_buffer[8];
    double ram_buffer[8];
    double load_buffer[8];

    while(command!="exit"){
        std::cout<<"enter the command"<<std::endl;
        std::cin>>command;
        if(command=="kbd"){
            kbd(kbd_buffer);
        }
        else if(command == "gpu"){
            gpu(ram_buffer);
        }
        else if(command == "cpu"){
            cpu(ram_buffer);
        }
        else if(command == "disk"){
            disk(ram_buffer,load_buffer);
        }
        else if(command =="ram"){
            ram(kbd_buffer,ram_buffer,load_buffer);
        }

    }
}
