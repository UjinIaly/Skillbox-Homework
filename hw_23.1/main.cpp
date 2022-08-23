#include <iostream>

#define MONDAY "monday"
#define TUESDAY "tuesday"
#define WEDNESDAY "wednesday"
#define THURSDAY "thursday"
#define FRIDAY "friday"
#define SATURDAY "saturday"
#define SUNDAY "sunday"
#define WTF "what???"

int main(){
 
    std::cout<<"enter the number of day"<<std::endl;
    int number=0;
    std::cin>>number;
    switch (number) {
        case 1:std::cout<<MONDAY<<std::endl;
        break;
        case 2:std::cout<<TUESDAY<<std::endl;
        break;
        case 3:std::cout<<WEDNESDAY<<std::endl;
        break;
        case 4:std::cout<<THURSDAY<<std::endl;
        break;
        case 5:std::cout<<FRIDAY<<std::endl;
        break;
        case 6:std::cout<<SATURDAY<<std::endl;
        break;
        case 7:std::cout<<SUNDAY<<std::endl;
        break;
        default:std::cout<<WTF<<std::endl;
    }
}
