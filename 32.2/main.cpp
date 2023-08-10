#include <iostream>
#include "nlohmann/json.hpp"
#include <map>
#include <fstream>

void read(nlohmann::json& data){
    std::ifstream file("../films.json");
    file >> data;
}

void search(const std::string name, nlohmann::json& data){
    for( auto it = data.begin(); it != data.end();it++){
        auto film = data[it.key()];
        auto actors = film["actors"];
        for(auto actors_it = actors.begin(); actors_it != actors.end(); actors_it++){
            if(actors_it.key() == name || actors_it.key().find(name) < actors_it.key().length()){
                std::cout << actors_it.key() << ": " << it.key() << " (" << actors_it.value() << ")." << std::endl;
                return;
            }
        }
    }
    std::cout<<"I do not know such an actor"<<std::endl;
}

int main(){
    nlohmann::json data;
    read(data);
    std::cout<<"input actor name"<<std::endl;
    std::string name;
    std::cin>>name;
    search(name, data);
}