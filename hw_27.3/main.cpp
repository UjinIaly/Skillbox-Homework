#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
class TEAM{
    std::string temp;
public:
    std::string manager_name;
    std::vector<std::string> workers_names;
    std::vector<std::string> working;
    int workers_count;
    TEAM(int workers, std::string name):workers_count(workers),manager_name(name){
       for(size_t i=0;i<workers_count;++i){
           std::cout<<"enter worker names"<<std::endl;
           std::cin>>temp;
           workers_names.push_back(temp);
           working.push_back("None");
       }
    }
    bool team_check(){
        for(size_t i = 0 ;i<workers_count;++i){
            if(working[i]!="A"&&working[i]!="B"&&working[i]!="C"){ return false;}
        }
        return true;
    }
};

class COMPANY{
    std::string boss;
    int teams_number;
    std::string temp;
    int count;
public:
    std::vector<TEAM> _teams;
    COMPANY(int teams,std::string boss_name):teams_number(teams),boss(boss_name){
        for(size_t i =0;i<teams_number;++i){
            std::cout<<"enter how many workers will be in the team and name of manager"<<std::endl;
            std::cin>>count>>temp;
            _teams.push_back(TEAM(count,temp));
        }
    }
    bool company_check(){
       for(size_t i = 0;i<teams_number;++i){
           if(!_teams[i].team_check()){return false;}
       }
       return true;
    };
};

int main() {

    int number;
    int tasks_count;
    std::string boss_name;
    int manager_number=0;
    std::vector<std::string> tasks;
    int free_task=0;
    int last_free_worker=0;
    std::cout<<"enter number of teams and who directs the company"<<std::endl;

    std::cin>>number>>boss_name;
    COMPANY company(number,boss_name);
    std::cout<<"let's start work"<<std::endl;
    std::cout<<"manager of the 1 group - "<<company._teams[0].manager_name<<std::endl;
    while(!company.company_check()){
        std::cout<<"enter the number"<<std::endl;
        std::cin>>number;
        std::srand(number+manager_number);
        tasks_count = std::rand()%company._teams[manager_number].workers_count+1;
        for(size_t i = 0;i<tasks_count;++i){
            switch (std::rand()%3) {
                case 0:
                    tasks.push_back("A");
                    break;
                case 1:
                    tasks.push_back("B");
                    break;
                case 2:
                    tasks.push_back("C");
                    break;
            }
        }
        for(size_t j = 0;j<tasks_count;++j) {
            if (company._teams[manager_number].team_check()) {
                ++manager_number;
                std::cout<<"manager of the "<<manager_number+1<<" group - "<<company._teams[manager_number].manager_name<<std::endl;
                last_free_worker = 0;
            }
            else{
                company._teams[manager_number].working[last_free_worker] = tasks[free_task];
                std::cout<<company._teams[manager_number].workers_names[last_free_worker]<<" gets the task - "<<tasks[free_task]<<std::endl;
                ++free_task;
                ++last_free_worker;
            }

        }

    }
    std::cout<<"everyone is busy"<<std::endl;
}
