#include <iostream>
#include <cmath>
#define PI 3.14

struct BoundingBoxDimensions{
    double length;
    double height;
};

class Shape{
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
    void printParams(Shape *shape){
        std::cout <<"Type: " << shape->type() << std::endl;
        std::cout <<"Square " << shape->square() << std::endl;
        std::cout <<"Length: " << shape->dimensions().length << std::endl;
        std::cout <<"Height " << shape->dimensions().height << std::endl;

    }

};

class Circle : public Shape{

    double radius;
public:
    Circle(double _radius):radius(_radius){};

    virtual double square(){
        return PI*radius*radius;
    }
    virtual BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions Box{radius*2,radius*2};
        return Box;
    }
    virtual std::string type(){
        std::cout<<"Circle"<<std::endl;
    }

};

class Rectangle : public Shape{

    double length;
    double height;
public:
    Rectangle(double _length,double _height):length(_length),height(_height){};
    double square(){
        return length*height;
    }
    BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions Box{length,height};
        return Box;
    }
    std::string type(){
        std::cout<<"Rectangle"<<std::endl;
    }

};

class Triangle : public Shape{

    double side_1;
    double side_2;
    double side_3;
    double p = (side_3+side_2+side_1)/2;
public:
    Triangle(double _side_1,double _side_2, double _side_3) : side_1(_side_1),side_2(_side_2),side_3(_side_3){};
    double square(){
        return sqrt(p*(p-side_1)*(p-side_3)*(p-side_2));
    }
    BoundingBoxDimensions dimensions(){
        double radius = side_1 * side_2 * side_3 / (4 * sqrt(p*(p - side_1)*(p - side_2)*(p - side_3)));
        BoundingBoxDimensions Box{radius*2,radius*2};
        return Box;
    }
    std::string type(){
        std::cout<<"Triangle"<<std::endl;
    }

};


int main() {
    Shape* c = new Circle(10);
    c->printParams(c);




}
