#include <iostream>
#include <map>
#include <string>

struct caller{
    std::string number;
    std::string name;
};

int main() {

    int command =0;
    caller customer;
    std::map<std::string,std::string> directory;

    std::cout <<"what do you want to do?"<<std::endl;
    std::cin>>command;

    if(command==1){
        std::cout<<"write name and number"<<std::endl;
        std::cin>>customer.name>>customer.number;
        directory.insert(std::pair<std::string,std::string>(customer.name,customer.number));
    }
    else if(command ==2){
        std::cout <<"enter the subscriber's number to find out his name"<<std::endl;
        std::cin>>customer.number;
        for(std::map<std::string,std::string>::iterator it=directory.begin();it!=directory.end();++it){
            if(it->second==customer.number){
                std::cout<<it->first<<" ";
            }
        }

    }
    else if(command ==2){
        std::cout <<"enter the subscriber's name to find out his number"<<std::endl;
        std::cin>>customer.name;
        for(std::map<std::string,std::string>::iterator it=directory.begin();it!=directory.end();++it){
            if(it->first==customer.name){
                std::cout<<it->second<<" ";
            }
        }

    }

}
