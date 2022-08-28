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
    void play(){
        if(in_current){
            std::cout<<"error"<<std::endl;
        }
        else {
            std::string temp_name;
            std::tm temp_date;
            int temp_dur;
            std::cout<<"enter the name of song"<<std::endl;
            std::cin>>temp_name;
            std::cout<<"enter the date of creation"<<std::endl;
            std::cin >> std::get_time(&temp_date, "%Y/%m/%d");
            std::cout<<"enter duration"<<std::endl;
            std::cin>>temp_dur;
            song_name.push_back(temp_name);
            born_date.push_back(temp_date);
            duration.push_back(temp_dur);
            std::cout << "playing" << std::endl;
            std::cout << "'" << temp_name << "' date of creation: " << std::asctime(&temp_date) << " duration: " << temp_dur<< std::endl;
            in_current = true;
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
        int i = std::rand() % (duration.size());
        std::cout << "playing" << std::endl;
        std::cout << "'"<<song_name[i]<< "' date of creation: " << std::asctime(&born_date[i]) << " duration: " << duration[i] << std::endl;
        in_current=true;
    }
    void stop(){
        if(in_current){
            std::cout<<"stop"<<std::endl;
            in_current = false;
        }
        else{
            std::cout<<"error"<<std::endl;
        }
    }
};


int main() {

    std::string command;
    PLAYER player ;
    srand(time(nullptr));




    while(command!= "exit"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command == "play"){
            player.play();
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
