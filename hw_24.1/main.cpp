#include <iostream>
#include <ctime>
#include <string>
#include <map>

int main() {

    std::string command;
    int task_number=1;
    std::string task_name;
    std::map<std::string,double> tasks_info;
    std::time_t start;
    std::time_t end;
    bool in_current=false;

    while(command!="exit"){
        std::cout<<"what do tou want to do?"<<std::endl;
        std::cin>>command;
        if(command=="begin"){
            if(in_current){
                end = std::time(nullptr);
                tasks_info.insert(std::pair<std::string,double>(std::to_string(task_number)+"'"+task_name+"'"" execution time: ",std::difftime(end,start)));
                ++task_number;
            }
            std::cout<<"enter name of the task"<<std::endl;
            std::cin>>task_name;
            start = std::time(nullptr);
            in_current=true;
        }
        else if(command=="end"){
            end = std::time(nullptr);
            tasks_info.insert(std::pair<std::string,double>(std::to_string(task_number)+"'"+task_name+"'"" execution time: ",std::difftime(end,start)));
            ++task_number;
            in_current=false;
        }
        else if(command == "status"){
            for(std::map<std::string,double>::iterator it = tasks_info.begin();it!=tasks_info.end();++it) {
                std::cout << it->first <<it->second<<std::endl;
            }
        }
    }



}
