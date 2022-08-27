#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

class PLAYER{
private:
    bool in_current = false;
    std::vector<std::string> song_name;
    std::vector<std::tm> born_date;
    std::vector<int> duration;
public:
    void play(std::string name,std::tm date,int dur){
        if(!in_current) {
            song_name.push_back(name);
            born_date.push_back(date);
            duration.push_back(dur);
            std::cout << "playing" << std::endl;
            std::cout << name << ". date of creation: " << std::asctime(&date) << " duration: " << dur << std::endl;
            in_current = true;
        }
        else{
            std::cout<<"error"<<std::endl;
        }
    }
    void pause(){
        if(in_current){
            std::cout<<"pause"<<std::endl;
            in_current= false;
        }
        else{
            std::cout<<"error"<<std::endl;
        }

    }
    void next() {
        int i = std::rand() % (duration.size() + 1);
        std::cout << "playing" << std::endl;
        std::cout << song_name[i]<< ". date of creation: " << std::asctime(&born_date[i]) << " duration: " << duration[i] << std::endl;
        in_current=true;
    }
    void stop(){
        if(!in_current){
            std::cout<<"stop"<<std::endl;
            in_current = false;
        }
    }
};


int main() {

    std::string command;
    PLAYER player ;
    std::string temp_name;
    std::time_t t=std::time(nullptr);
    std::tm temp_time = *std::localtime(&t);
    int temp_dur;


    while(command!= "exit"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command == "play"){
            std::cout<<"enter the name of song"<<std::endl;
            std::cin>>temp_name;
            std::cout<<"enter the date of creation"<<std::endl;
            std::cin >> std::get_time(&temp_time, "%Y/%m/%d");
            std::cout<<"enter duration"<<std::endl;
            std::cin>>temp_dur;
            player.play(temp_name,temp_time,temp_dur);
        }
        else if(command == "pause"){
            player.pause();
        }
        else if(command == "next"){
            player.next();
        }
        else if(command == "stop"){
            player.stop();
        }
        else{
            std::cout<<"error"<<std::endl;
        }


    }
}
