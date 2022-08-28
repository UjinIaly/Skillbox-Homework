#include <iostream>
#include <map>
#include <vector>

class PHONE{
private:
    std::map<std::string,unsigned long long > name_number;
    std::map<unsigned long long ,std::string> number_name;
    long long temp_number;
    std::string temp_name;
    char text=0;

public:
    void add(){
        std::cout<<"enter number"<<std::endl;
        std::cin>>temp_number;
        if(temp_number%10000000000<1){return;}
        std::cout<<"enter name"<<std::endl;
        std::cin>>temp_name;
        name_number.insert(std::pair<std::string,long long >(temp_name,temp_number));
        number_name.insert(std::pair<long long,std::string >(temp_number,temp_name));
    }
    void call(){
        std::cout<<"enter number or name"<<std::endl;
        std::cin>>temp_name;
        for(size_t i=0;i<temp_name.size();++i){
            if(temp_name[i]>='0'&&temp_name[i]<='9'){
                temp_number = std::stoll(temp_name);
                std::map<unsigned long long, std::string>::iterator it = number_name.find(temp_number);
                if(it == number_name.end()){
                    std::cout<<"error"<<std::endl;
                    return;
                }
                std::cout<<"calling to: "<<it->second<<std::endl;
                return;
            }
        }

        std::map<std::string, unsigned long long>::iterator it = name_number.find(temp_name);
        if(it == name_number.end()){
            std::cout<<"error"<<std::endl;
            return;
        }
        std::cout<<"calling to: "<<it->second<<std::endl;
    }
    void sms(){
        std::cout<<"enter number or name"<<std::endl;
        std::cin>>temp_name;
        for(size_t i=0;i<temp_name.size();++i){
            if(temp_name[i]>='0'&&temp_name[i]<='9'){
                temp_number = std::stoll(temp_name);
                std::map<unsigned long long, std::string>::iterator it = number_name.find(temp_number);
                if(it == number_name.end()){
                    std::cout<<"error"<<std::endl;
                    return;
                }
                std::cout<<"write a message"<<std::endl;
                std::cin>>text;
                for(unsigned int j = 0;j<256;++j){
                    std::cin>>std::noskipws>>text;
                    if(text=='\n'){break;}
                }
                std::cout<<"sending to: "<<it->second<<std::endl;
                return;
            }
        }

        std::map<std::string, unsigned long long>::iterator it = name_number.find(temp_name);
        if(it == name_number.end()){
            std::cout<<"error"<<std::endl;
            return;
        }
        std::cout<<"write a message"<<std::endl;
        std::cin>>text;
        for(unsigned int j = 0;j<256;++j){
            std::cin>>std::noskipws>>text;
            if(text=='\n'){break;}
        }
        std::cout<<"sending to : "<<it->second<<std::endl;
   }
};

int main() {

    PHONE phone;
    std::string command;
    while(command != "exit"){
        std::cout<<"enter the command"<<std::endl;
        std::cin>>command;
        if(command == "add"){
            phone.add();
        }
        else if(command == "call"){
            phone.call();
        }
        else if(command == "sms"){
            phone.sms();
        }
        else {
            std::cout<<"error"<<std::endl;
        }

    }
}
