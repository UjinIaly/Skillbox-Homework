#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

std::vector<std::string> done_orders;
std::mutex access;
bool free_kitchen=true;

void cooking(std::string dish){
    while(!free_kitchen){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
        free_kitchen = false;
        std::cout << "start cooking " << dish << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11));
        access.lock();
        std::cout << dish << " is ready to delivery" << std::endl;
        done_orders.push_back(dish);
        free_kitchen = true;
        access.unlock();

}

void delivering_orders(){
    for(size_t i = 0;i<10;++i){
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout<<done_orders[i]<<" order has been sent"<<std::endl;
    }
};


int main() {
    std::vector<std::string> dishes = {"pizza","soup","steak","salad","sushi"};
    std::vector<std::thread> currents;
    std::srand(unsigned(std::time(nullptr)));
    int dish_number = 0;
    std::thread delivery(delivering_orders);
    for(size_t i = 0;i<10;++i){
        std::this_thread::sleep_for(std::chrono::seconds (std::rand()%6));
        dish_number = std::rand()%5;
        std::cout<<"received order for "<<dishes[dish_number]<<std::endl;
        currents.push_back(std::thread(cooking,dishes[dish_number]));

    }
    delivery.join();
    for(size_t i = 0;i<10;++i){
        currents[i].join();
    }

    std::cout<<"nice job! All orders has been sent"<<std::endl;

}
