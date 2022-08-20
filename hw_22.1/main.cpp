#include <iostream>
#include <map>
#include <string>

struct caller{
    std::string number;
    std::string name;
};

int main() {

    std::string command;
    caller customer;
    std::map<std::string,std::string> directory;

    while (command!="q") {
        std::cout <<"what do you want to do?"<<std::endl;
        std::cin>>command;
        if (command == "1") {
            std::cout << "write number and name" << std::endl;
            std::cin >> customer.number >> customer.name;
            directory.insert(std::pair<std::string, std::string>(customer.number, customer.name));
        } else if (command == "2") {
            std::cout << "enter the subscriber's number to find out his name" << std::endl;
            std::cin >> customer.number;
            for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); ++it) {
                if (it->first == customer.number) {
                    std::cout << it->second << " ";
                }
            }
            std::cout<<std::endl;

        }
        else if (command == "3") {
            std::cout << "enter the subscriber's name to find out his number" << std::endl;
            std::cin >> customer.name;
            for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); ++it) {
                if (it->second == customer.name) {
                    std::cout << it->first <<std::endl;
                    break;
                }
            }

        }
        else if (command == "4") {
            for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); ++it) {
                    std::cout << it->first << " "<<it->second<<std::endl;
t
            }

        }


    }


}
