#include <iostream>
#include <ctime>
int get_timer(){
    std::cout<<"set the timer"<<std::endl;
    std::cout<<"minutes"<<std::endl;
    int time=0;
    int temp=0;
    std::cin>>temp;
    time+=60*temp;
    std::cout<<"seconds"<<std::endl;
    std::cin>>temp;
    time+=temp;
    return time;
}

int main() {
    int time = get_timer();
    std::time_t t = std::time(nullptr);
    std::time_t counter = std::time(nullptr);
    int i=0;
    while(counter!=t+time){
        if((counter = std::time(nullptr)) == t+i){
            std::cout<<"time is up"<<std::endl;
            ++i;
        }
    }
    std::cout<<"ding ding ding mf"<<std::endl;
}
