#include <iostream>
#include "func.h"

void scalpel(point start_points,point end_points){
    std::cout<<"a cut is made between the points: ("<<start_points.x<<","<<start_points.y<<") and ("<<end_points.x<<","<<end_points.y<<")"<<std::endl;
}
void hemostat(point temp_points){
    std::cout<<"clamp to the point: ("<<temp_points.x<<","<<temp_points.y<<")"<<std::endl;
}
void tweezers(point temp_points){
    std::cout<<"tweezers to the point: ("<<temp_points.x<<","<<temp_points.y<<")"<<std::endl;
}
void suture(point start_points,point end_points){
    std::cout<<"a sewn between the points: ("<<start_points.x<<","<<start_points.y<<") and ("<<end_points.x<<","<<end_points.y<<")"<<std::endl;
}
int main() {
    point start_points = {0,0};
    point end_points = {0,0};
    point temp_points = {0,0};
    std::string command;
    bool in_process=false;

    while(true){
        std::cout<<"enter the command"<<std::endl;
        std::cin>>command;
        if(!in_process&&command == "scalpel"){
            std::cout<<"enter the points between which the cut will be made"<<std::endl;
            std::cin>>start_points.x>>start_points.y>>end_points.x>>end_points.y;
            scalpel(start_points,end_points);
            in_process=true;
        }
        else if(in_process&&command =="hemostat"){
            std::cout<<"enter the point to clamp"<<std::endl;
            std::cin>>temp_points.x>>temp_points.y;
            hemostat(temp_points);
        }
        else if(in_process&&command =="tweezers") {
            std::cout << "enter the point to tweezers" << std::endl;
            std::cin >> temp_points.x >> temp_points.y;
            tweezers(temp_points);
        }
        else if(in_process&&command =="suture") {
            std::cout << "enter the points to sew up" << std::endl;
            std::cin >> temp_points.x >> temp_points.y;
            if(start_points.x!=temp_points.x||start_points.y!=temp_points.y){
                std::cout<<"error"<<std::endl;
                continue;
            }
            std::cin >> temp_points.x >> temp_points.y;
            if(end_points.x!=temp_points.x||end_points.y!=temp_points.y){
                std::cout<<"error"<<std::endl;
                continue;
            }
            suture(start_points,end_points);
            in_process = false;
            break;

        }
        else{
            std::cout<<"error"<<std::endl;
        }
    }
    std::cout<<"grats!"<<std::endl;
}
