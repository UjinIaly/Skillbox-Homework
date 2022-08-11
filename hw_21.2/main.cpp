#include <iostream>
#include <vector>
struct area{
    enum extensions{
        BARN=1,
        BATHHOUSE=2,
        GARAGE=4,
        HOUSE_BAKE=8,
        BATH_BAKE=16
    }extensions;
    struct extensions_square{
        int barn_s = 0;
        int bathhouse_s = 0;
        int garage_s = 0;
        int house_bake_s = 0;
        int bath_bake_s = 0;

    };
    struct house{
        struct floor{
            int living_s[3]={0,0,0};
            int children_s[3]={0,0,0};
            int kitchen_s[3]={0,0,0};
            int bedroom_s[3]={0,0,0};
            int bathroom_s[3]={0,0,0};
        }floor;
    }house;

};
enum room_type{
        living=1,
        children=2,
        kitche4,
        bedroom=8,
        bathroom=16
    };
int main() {
    std::cout<<"how many houses will there be?"<<std::endl;
    size_t qua;
    std::cin>>qua;

    area building[qua];
    int ext[qua];
    std::string command;

    //building[0].house.floor.living_s[0]=5;
    //building[0].extensions;

    for(int i=0;i<qua;++i){
        std::cout<<"buildings around: "<<std::endl<<"barn? [y/n]";
        std::cin>>command;
        if(command == "y"){ext[i]|=area::BARN;}
        else if(command != "n"){std::cout<<"wrong input"<<std::endl; ext[i]&=area::BARN;--i;continue;}

        std::cout<<"bathhouse? [y/n]";
        std::cin>>command;
        if(command == "y"){ext[i]|=area::BATHHOUSE;}
        else if(command != "n"){std::cout<<"wrong input"<<std::endl; ext[i]&=area::BATHHOUSE;--i;continue;}

        std::cout<<"garage? [y/n]";
        std::cin>>command;
        if(command == "y"){ext[i]|=area::GARAGE;}
        else if(command != "n"){std::cout<<"wrong input"<<std::endl; ext[i]&=area::GARAGE;--i;continue;}

        std::cout<<"garage? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){ext[i]|=area::GARAGE;}













    }





}
