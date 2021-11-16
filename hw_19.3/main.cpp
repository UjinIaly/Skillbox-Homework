#include <iostream>
#include <fstream>
int main() {
    std::string name;
    double sum=0;
    double temp;
    double max=0;
    std::ifstream file;
    file.open("/home/ujin_ialy/Skillbox-Homework/hw_19.3/info.txt");
    while(!file.eof()){
        file >> name >> name >> temp >> name;
        sum+=temp;
        if(temp>max){max=temp;}
    }
    std::cout<<"general amount of payments: "<<sum<<std::endl;
    std::cout<<"max payment: "<<max<<std::endl;
    file.close();
}
