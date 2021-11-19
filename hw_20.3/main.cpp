#include <iostream>
#include <fstream>
int main() {

    std::ifstream river("/home/ujin_ialy/Skillbox-Homework/hw_20.3/river.txt",std::ios::app);
    std::ofstream basket("/home/ujin_ialy/Skillbox-Homework/hw_20.3/basket.txt");
    char fish[20];
    while(true) {
        std::cout << "input name of the fish" << std::endl;
        std::cin >> fish;
        char in_river[20];
        while (!river.eof()) {
            river >>in_river;
            if (*in_river == *fish) {
                basket << fish << std::endl;
                break;
            }

        }
        if(river.eof()){std::cout<<"there if no such fish in this river"<<std::endl;}
    river.seekg(0);
    }



}
