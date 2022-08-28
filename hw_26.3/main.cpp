#include <iostream>
#include <vector>

class INTERFACE{
private:
    std::vector<std::vector<int>> screen{80,std::vector<int>(50)};

    int field_x=0;
    int field_y=0;
    int field_length=0;
    int field_height=0;

    void fill(){
        null_screen();
        for(size_t i=field_x;i<field_x+field_length;++i){
            for(size_t j=field_y;j<field_y+field_height;++j){
                screen[i][j]=1;
            }
        }
    }

public:
    void null_screen(){
        for(size_t i=0;i<80;++i){
            for(size_t j=0;j<50;++j){
                screen[i][j]=0;
            }
        }
    }
    void display(){
        for(size_t i=0;i<80;++i){
            for(size_t j=0;j<50;++j){
                std::cout<<screen[i][j];
            }
            std::cout<<std::endl;
        }
    }
    void move(int x,int y){
        if(field_x+x>80||field_y+y>50||field_x+x<0||field_y+y<0){
            std::cout<<"error"<<std::endl;
            return;
        }
        else {
            field_x += x;
            field_y += y;
            std::cout<<"new coordinates: ("<<field_x<<","<<field_y<<")"<<std::endl;
            if(field_x+field_length>80){
                field_length -=(field_x+field_length-80);
            }
            if(field_y+field_height>50){
                field_height -=(field_y+field_height-50);
            }
        }
        fill();

    }
    void resize(size_t length, size_t height){
        if(length>80||height>50){
            std::cout<<"error"<<std::endl;
            return;
        }
        else{
            field_length = length;
            field_height = height;
            std::cout<<"new sizes: length - "<<field_length<<", height - "<<field_height<<std::endl;
        }
        fill();

    }



};
int main() {

    std::string command;
    INTERFACE interface;
    interface.null_screen();
    int x = 0;
    int y = 0;
    int length = 0;
    int height = 0;
    while(command != "close"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command == "move"){
            std::cout<<"enter vector"<<std::endl;
            std::cin>>x>>y;
            interface.move(x,y);
        }
        else if(command == "resize"){
            std::cout<<"enter new length and height"<<std::endl;
            std::cin>>length>>height;
            interface.resize(length,height);
        }
        else if(command == "display"){
            interface.display();
        }
        else {
            std::cout<<"error"<<std::endl;
        }
    }
}
