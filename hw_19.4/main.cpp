#include <iostream>
#include <fstream>
int main() {
    char flat[4] ;
    std::string way;
    std::ifstream file;

    std::cout<<"input the way to the file"<<std::endl;
    std::cin>>way;

    file.open(way,std::ios::binary);
    file.read(flat, sizeof(char[4]));

    if(*flat==-119&&*(flat+1)=='P'&&*(flat+2)=='N'&&*(flat+3)=='G'){std::cout<<"yes, this is PNG file"<<std::endl;}
    else{std::cout<<"NO, this isn't a PNG file"<<std::endl;}
    file.close();
}
