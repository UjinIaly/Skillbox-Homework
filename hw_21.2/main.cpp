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
int main() {
    //start
    std::cout<<"how many houses will there be?"<<std::endl;
    size_t qua;
    std::cin>>qua;

    area building[qua];
    int ext[qua];
    std::string command;
    double all_square[2]={0,0};
    std::cout<<"what is the area of the village?"<<std::endl;
    std::cin>>all_square[0];


    for(size_t i=0;i<qua;++i){
        //buildings around the house
        std::cout<<"Buildings around:"<<std::endl<<"barn? [y/n]"<<std::endl;
        do{std::cin>>command;}
        while(command!="y"&&command!="n");
        if(command == "y"){
            ext[i]|=area::BARN;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.barn_s;
            all_square[1]+=building[i].extensions_square.barn_s;
        }

        std::cout<<"bathhouse? [y/n]"<<std::endl;
        do{std::cin>>command;}
        while(command!="y"&&command!="n");
        if(command == "y"){
            ext[i]|=area::BATHHOUSE;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.bathhouse_s;
            all_square[1]+=building[i].extensions_square.bathhouse_s;
        }

        std::cout<<"garage? [y/n]"<<std::endl;
        do{std::cin>>command;}
        while(command!="y"&&command!="n");
        if(command == "y"){
            ext[i]|=area::GARAGE;
            std::cout<<"square?"<<std::endl;
            std::cin>>building[i].extensions_square.garage_s;
            all_square[1]+=building[i].extensions_square.garage_s;
        }

        std::cout<<"house pipe? [y/n]"<<std::endl;
        do{std::cin>>command;}
        while(command!="y"&&command!="n");
        if(command == "y"){ext[i]|=area::HOUSE_PIPE;}

        std::cout<<"bath_pipe? [y/n]"<<std::endl;
        do{std::cin>>command;}
        while(command!="y"&&command!="n");
        if(command == "y"){ext[i]|=area::BATH_PIPE;}

        //house
        //count of floors
        size_t floors=0;
        do{
            std::cout<<"how many floors wil be in the house?"<<std::endl;
            std::cin>>floors;
        }
        while(floors==0||floors>3);

        size_t count_of_rooms=0;

        for (size_t j = 0; j < floors; ++j) {
            count_of_rooms=0;
            while(count_of_rooms<2||count_of_rooms>4) {
                building[i].house.floor.living_s[j]=0;
                building[i].house.floor.children_s[j]=0;
                building[i].house.floor.kitchen_s[j]=0;
                building[i].house.floor.bedroom_s[j]=0;
                building[i].house.floor.bathroom_s[j]=0;

                std::cout << "what kind of rooms will there be?" << std::endl;

                std::cout << "kitchen? [y/n]" << std::endl;
                std::cin >> command;
                if (command == "y") {
                    std::cout << "square?" << std::endl;
                    std::cin >> building[i].house.floor.kitchen_s[j];
                    ++count_of_rooms;
                    all_square[1]+=building[i].house.floor.kitchen_s[j];
                }
                std::cout << "living? [y/n]" << std::endl;
                std::cin >> command;
                if (command == "y") {
                    std::cout << "square?" << std::endl;
                    std::cin >> building[i].house.floor.living_s[j];
                    ++count_of_rooms;
                    all_square[1]+=building[i].house.floor.living_s[j];
                }
                std::cout << "children? [y/n]" << std::endl;
                std::cin >> command;
                if (command == "y") {
                    std::cout << "square?" << std::endl;
                    std::cin >> building[i].house.floor.children_s[j];
                    all_square[1]+=building[i].house.floor.children_s[j];
                    ++count_of_rooms;
                }
                std::cout << "bedroom? [y/n]" << std::endl;
                std::cin >> command;
                if (command == "y") {
                    std::cout << "square?" << std::endl;
                    std::cin >> building[i].house.floor.bedroom_s[j];
                    all_square[1]+=building[i].house.floor.bedroom_s[j];
                    ++count_of_rooms;
                }
                std::cout << "bathroom? [y/n]" << std::endl;
                std::cin >> command;
                if (command == "y") {
                    std::cout << "square?" << std::endl;
                    std::cin >> building[i].house.floor.bathroom_s[j];
                    all_square[1]+=building[i].house.floor.bathroom_s[j];
                    ++count_of_rooms;
                }
            }

        }
    }

    std::cout<<"the area occupied by buildings: "<<all_square[1]/all_square[0]*100<<"%"<<std::endl;
    if(all_square[1]/all_square[0]>100){
        std::cout<<"i think something is wrong, you should rerun this program and do all again"<<std::endl;
    }





}
