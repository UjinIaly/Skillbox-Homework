#include <iostream>
#include <fstream>
int main() {
    char flat[3] ;
    std::string way;
    std::ifstream file;

    std::cout<<"input the way to the file"<<std::endl;
    std::cin>>way;

    file.open(way,std::ios::binary);
    file.seekg(1);
    file.read(flat, sizeof(char[3]));

    if(*flat=='P'&&*(flat+1)=='N'&&*(flat+2)=='G'){std::cout<<"yes, this is PNG file"<<std::endl;}
    else{std::cout<<"NO, this isn't a PNG file"<<std::endl;}
    file.close();
}
