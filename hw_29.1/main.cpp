#include <iostream>
#include <vector>

class Talent{
public:
    std::vector<std::string> talents;
    virtual void add_talent() = 0;

};

class Dog : public Talent{

    std::string Dog_name;

public:

    Dog(std::string name):Dog_name(name){}

    void show_talent(){
        for(size_t i=0;i<talents.size();++i){
            std::cout<<"it can '"<<talents[i]<<"'"<<std::endl;
        }
    }

    virtual void add_talent(){
        std::string temp_talent;
        std::cin>>temp_talent;
        talents.push_back(temp_talent);
    }

};

int main() {
    std::string command;
    Dog dog("Steve");
    while(command !="q"){
        std::cout<<"enter command" <<std::endl;
        std::cin>>command;
        if(command == "show"){
            dog.show_talent();
        }
        else if(command == "add"){
            dog.add_talent();
        }
        else if(command!="q"){
            std::cout<<"i don't know this command"<<std::endl;
        }

    }

    std::cout<<" nice job!"<<std::endl;
}
