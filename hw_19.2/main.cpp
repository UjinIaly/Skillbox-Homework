#include <iostream>
#include <fstream>
int main() {
    std::string way;
    std::ifstream file;

    std::cout<<"input way to file";
    std::cin>>way;

    file.open(way);

    while(!file.eof()){
        std::getline(file,way);
        std::cout<<way;
        std::cout<<std::endl;
    }

    file.close();




}
