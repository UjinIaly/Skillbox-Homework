#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex station_access;

void arriving(int travel_time,std::string train){
    std::this_thread::sleep_for(std::chrono::seconds(travel_time));
    station_access.lock();
    std::cout<<"train - "<<train<<" arrived to the station"<<std::endl;
    std::cout<<"enter 'depart', when train will be ready for next travel"<<std::endl;
    std::string command;
    while(command!="depart"){
        std::cin>>command;
    }
    std::cout<<"train - "<<train<<" went from the platform"<<std::endl;
    station_access.unlock();
}

int main() {
    std::cout<<"enter travel time"<<std::endl;
    std::vector<int> travel_time(3);
    std::vector<std::string> trains = {"A","B","C"};
    for(size_t i = 0;i<3;++i){
        std::cin>>travel_time[i];
    }

    std::thread train1(arriving,travel_time[0],trains[0]);
    std::thread train2(arriving,travel_time[1],trains[1]);
    std::thread train3(arriving,travel_time[1],trains[2]);

    train1.join();
    train2.join();
    train3.join();

    std::cout<<"all train left from the station"<<std::endl;

}
