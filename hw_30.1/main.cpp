#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string command;
    while(command != "exit"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command == "get"){
            cpr::Response answer = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout<<answer.text<<std::endl;
        }
        else if(command == "post"){
            std::string phrase;
            std::cout<<"enter phrase"<<std::endl;
            std::cin>>phrase;
            cpr::Response answer = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                             cpr::Payload({{"phrase: ",phrase.c_str()}}));
            std::cout<<answer.text<<std::endl;
        }
        else if(command == "put"){
            std::string phrase;
            std::cout<<"enter phrase"<<std::endl;
            std::cin>>phrase;
            cpr::Response answer = cpr::Put(cpr::Url("http://httpbin.org/put"),
                                             cpr::Header ({{"phrase: ",phrase.c_str()}}));
            std::cout<<answer.text<<std::endl;

        }
        else if(command == "delete"){
            cpr::Response answer = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout<<answer.text<<std::endl;
        }
        else if(command == "patch"){
            cpr::Response answer = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout<<answer.text<<std::endl;
        }

    }

}
