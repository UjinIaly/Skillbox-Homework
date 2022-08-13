#include <iostream>
#include <vector>
struct area{
    enum extensions{
        BARN=1,
        BATHHOUSE=2,
        GARAGE=4,
        HOUSE_PIPE=8,
        BATH_PIPE=16
    }extensions;
    struct extensions_square{
        int barn_s = 0;
        int bathhouse_s = 0;
        int garage_s = 0;

    }extensions_square;

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
        kitchen=4,
        bedroom=8,
        bathroom=16
    };
int main() {
    //start
    std::cout<<"how many houses will there be?"<<std::endl;
    size_t qua;
    std::cin>>qua;

    area building[qua];
    int ext[qua];
    std::string command;

    //building[0].house.floor.living_s[0]=5;
    //building[0].extensions;

    for(int i=0;i<qua;++i){
        //buildings around the house
        std::cout<<"Buildings around:"<<std::endl<<"barn? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){
            ext[i]|=area::BARN;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.barn_s;
        }



        std::cout<<"bathhouse? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){
            ext[i]|=area::BATHHOUSE;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.bathhouse_s;
        }

        std::cout<<"garage? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){
            ext[i]|=area::GARAGE;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.garage_s;
        }

        std::cout<<"house pipe? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){ext[i]|=area::HOUSE_PIPE;}

        std::cout<<"bath_pipe? [y/n]";
        do{std::cin>>command;std::cout<<"wrong input"<<std::endl;}
        while(command!="y"||command!="n");
        if(command == "y"){ext[i]|=area::BATH_PIPE;}

        //house
        //count of floors
        size_t floors=0;
        std::cout<<"how many floors wil be in the house?"<<std::endl;
        std::cin>>floors;
        for(size_t j=0;j<floors;++j){
            
        }





    }





}
