#include <iostream>
#include <vector>
#include <thread>
#include <map>
#include <string>
#include <mutex>

#define PATH_LENGTH 100

std::mutex access;

void progress(std::map<double,std::string>::const_iterator athlete){
    size_t second = 0;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        access.lock();
        if (second * athlete->first >= 100) {
            std::cout << athlete->second << " - FINISHED" << std::endl;
            access.unlock();
            break;
        } else {
            std::cout << athlete->second << " - " << athlete->first * second << "m" << std::endl;
        }
        ++second;
        access.unlock();
    }

}

int main() {
    std::map<double,std::string> participants;
    int temp_speed;
    std::string temp_name;
    std::vector<double> final_time(6);
    size_t j =0;


    for(size_t i=0;i<6;++i){
        std::cout<<"enter speed and name"<<std::endl;
        std::cin>>temp_speed>>temp_name;
        participants.insert(std::pair<double, std::string>(temp_speed,temp_name));
    }
    for(std::map<double,std::string>::iterator it = participants.begin();it!=participants.end();++it){
        final_time[j] = PATH_LENGTH/it->first;
        ++j;
    }
    j=0;
    std::map<double,std::string>::iterator swimmer = participants.begin();
    std::thread path1(progress,swimmer);
    ++swimmer;
    std::thread path2(progress,swimmer);
    ++swimmer;
    std::thread path3(progress,swimmer);
    ++swimmer;
    std::thread path4(progress,swimmer);
    ++swimmer;
    std::thread path5(progress,swimmer);
    ++swimmer;
    std::thread path6(progress,swimmer);

    path1.join();
    path2.join();
    path3.join();
    path4.join();
    path5.join();
    path6.join();
    j=5;
    std::cout<<"result: "<<std::endl;
    for(std::map<double,std::string>::reverse_iterator it = participants.rbegin();it!=participants.rend();++it){
        std::cout<<it->second<<" - "<<final_time[j]<<std::endl;
        --j;
    }

}
