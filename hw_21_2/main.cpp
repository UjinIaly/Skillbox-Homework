#include <iostream>
#include <cmath>
#include <math.h>

void add(float* x1, float* y1, float x2, float y2){
    *x1+=x2;
    *y1+=y2;
};
void subtract(float* x1, float* y1, float x2, float y2){
    *x1-=x2;
    *y1-=y2;
};
void scale(float* x1, float* y1, float k){
    *x1*=k;
    *y1*=k;
};
float length(float x1, float y1){
    return sqrt(x1*x1+y1*y1);
}
void normalize(float* x1, float* y1){
    float abs = sqrt(pow(*x1,2)+pow(*y1,2));
    *x1/=abs;
    *y1/=abs;
}
int main() {
    std::cout<<"what command you want to do ?"<<std::endl;
    std::string command;
    std::cin>>command;
    float x1,y1=0;
    float x2,y2=0;
    float k=0;
    if(command=="add"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>x1>>y1>>x2>>y2;
        add(&x1,&y1,x2,y2);
        std::cout<<"resulting vector: ("<<x1<<","<<y1<<")"<<std::endl;
    }
    else if(command=="subtract"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>x1>>y1>>x2>>y2;
        subtract(&x1,&y1,x2,y2);
        std::cout<<"resulting vector: ("<<x1<<","<<y1<<")"<<std::endl;
    }
    else if(command=="scale"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>x1>>y1;
        std::cout<<"enter the scalar"<<std::endl;
        std::cin>>k;
        scale(&x1,&y1,k);
        std::cout<<"resulting vector: ("<<x1<<","<<y1<<")"<<std::endl;
    }
    else if(command=="length"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>x1>>y1;
        std::cout<<"result: "<<length(x1,y1)<<std::endl;
    }
    else if(command=="normalize"){
        std::cout<<"enter the coordinates of the vectors"<<std::endl;
        std::cin>>x1>>y1;
        normalize(&x1,&y1);
        std::cout<<"resulting vector: ("<<x1<<","<<y1<<")"<<std::endl;
    }
    else {
        std::cout<<"something was wrong, try again"<<std::endl;
    }


}
