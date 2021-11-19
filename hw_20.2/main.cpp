#include <iostream>
#include <ctime>
#include <fstream>

int main() {
    std::srand(std::time(nullptr));
    size_t m;
    size_t n;
    std::cout<<"Input length and height of picture: "<<std::endl;
    std::cin>>m>>n;
    std::ofstream file("/home/ujin_ialy/Skillbox-Homework/hw_20.2/pic.txt");

    for(size_t i=0;i<m;++i){
        for(size_t j=0;j<n;++j){
            file<<std::rand()%2<<" ";
        }
       file<<std::endl;
    }
}
