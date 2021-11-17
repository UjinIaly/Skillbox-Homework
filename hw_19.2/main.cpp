#include <iostream>
#include <fstream>
int main() {
    char way[20];
    std::ifstream file;
    char buffer[200];
    std::cout<<"input way to file"<<std::endl;
    std::cin>>way;
    file.open(way,std::ios::binary);
    while(!file.eof()){
      file.read(buffer,sizeof(buffer));
      std::cout<<buffer;
    }

    file.close();




}
