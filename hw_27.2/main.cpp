#include <iostream>
#include <cmath>
#define PI 3.14
class figure{

public:
    double _square=0;
    double _perimeter=0;
    std::string _color;
};

class circle: public figure{
    double _radius;
public:
    circle(double radius,std::string color):_radius(radius){
        _color = color;
        _square = PI*radius*radius;
        _perimeter = radius*8;
        std::cout<<"circle. square: "<<_square<<" perimeter: "<<_perimeter<<" color: "<<_color<<std::endl;
    }

};
class rectangle: public figure{
    double _length;
    double _height;
public:
    rectangle(double length,double height,std::string color):_length(length),_height(height){
        _color = color;
        _square = _length*_height;
        _perimeter = 2*(_length+_height);
        std::cout<<"rectangle. square: "<<_square<<" perimeter: "<<_perimeter<<" color: "<<_color<<std::endl;
    }

};

class triangle: public figure{
    double _side;
public:
    triangle(double side,std::string color):_side(side){
        _color = color;
        _square = _side*_side*sqrt(3)/4;
        _perimeter = 4*_side;
        std::cout<<"triangle. square: "<<_square<<" perimeter: "<<_perimeter<<" color: "<<_color<<std::endl;
    }

};




int main() {
    std::string command;
    double side;
    double another_side;
    std::string color;
    while(command != "exit"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command == "circle"){
            std::cout<<"enter radius and color"<<std::endl;
            std::cin>>side>>color;
            circle(side,color);
        }
        else if(command == "rectangle"){
            std::cout<<"enter two sides and color"<<std::endl;
            std::cin>>side>>another_side>>color;
            rectangle(side,another_side,color);
        }
        else if(command == "box"){
            std::cout<<"enter side and color"<<std::endl;
            std::cin>>side>>color;
            rectangle(side,side,color);
        }
        else if(command == "triangle"){
            std::cout<<"enter side and color"<<std::endl;
            std::cin>>side>>color;
            rectangle(side,another_side,color);
        }
        else {
            std::cout<<"error"<<std::endl;
        }

    }
}
