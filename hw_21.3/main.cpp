#include <iostream>
#include <cmath>

struct vector{
    double x;
    double y;
};

void add(vector* a, vector b){
    a->x+=b.x;
    a->y+=b.y;
};
void subtract(vector* a, vector b){
    a->x-=b.x;
    a->y-=b.y;
};
void scale(vector* a, float k){
    a->x*=k;
    a->y*=k;
};
double length(vector a){
    return sqrt(pow(a.x,2)+pow(a.y,2));
}
void normalize(vector* a){
    double abs = sqrt(pow(a->x,2)+pow(a->y,2));
    a->x/=abs;
    a->y/=abs;
}


int main() {
    std::cout<<"what command you want to do ?"<<std::endl;
    std::string command;
    std::cin>>command;
    vector a={0,0};
    vector b={0,0};
    float k=0;
    if(command=="add"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>a.x>>a.y>>b.x>>b.y;
        add(&a,b);
        std::cout<<"resulting vector: ("<<a.x<<","<<a.y<<")"<<std::endl;
    }
    else if(command=="subtract"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>a.x>>a.y>>b.x>>b.y;
        subtract(&a,b);
        std::cout<<"resulting vector: ("<<a.x<<","<<a.y<<")"<<std::endl;
    }
    else if(command=="scale"){
        std::cout<<"enter the coordinates of the vector"<<std::endl;
        std::cin>>a.x>>a.y;
        std::cout<<"enter the scalar"<<std::endl;
        std::cin>>k;
        scale(&a,k);
        std::cout<<"resulting vector: ("<<a.x<<","<<a.y<<")"<<std::endl;
    }
    else if(command=="length"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>a.x>>a.y;
        std::cout<<"result: "<<length(a)<<std::endl;
    }
    else if(command=="normalize"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>a.x>>a.y;
        normalize(&a);
        std::cout<<"resulting vector: ("<<a.x<<","<<a.y<<")"<<std::endl;
    }
    else {
        std::cout<<"something was wrong, try again"<<std::endl;
    }


}
