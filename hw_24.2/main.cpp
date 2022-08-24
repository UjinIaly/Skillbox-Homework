#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

int main() {
    std::string name=" ";
    std::time_t t = std::time(nullptr);
    std::tm time_def = *std::localtime(&t);
    std::tm time = *std::localtime(&t);
    std::vector<std::tm> dates;
    std::tm min;

    while(true) {
        std::cout<<"enter name"<<std::endl;
        std::cin>>name;
        if(name=="end"){break;}
        std::cout<<"enter date"<<std::endl;
        std::cin >> std::get_time(&time, "%Y/%m/%d");
        if(time.tm_mon==time_def.tm_mon&&time.tm_mday==time_def.tm_mday){
            std::cout<<"HAPPY BIRTHDAY "<<name<<"!"<<std::endl;
        }
        if((time.tm_mday>=time_def.tm_mday&&time.tm_mon==time_def.tm_mon)||
            time.tm_mon>time_def.tm_mon){
            dates.push_back(time);
        }
    }

    for(size_t i=1;i<dates.size();++i){
        if(dates[i-1].tm_mon<dates[i].tm_mon){
            min = dates[i-1];
        }
        else if(dates[i-1].tm_mon==dates[i].tm_mon&&dates[i-1].tm_mday<dates[i].tm_mday){
            min = dates[i-1];
        }
    }
    std::cout<<asctime(&min)<<std::endl;

}
