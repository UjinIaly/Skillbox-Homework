#include <iostream>

#if defined SPRING
#define TEXT "spring"
#elif defined SUMMER
#define TEXT "summer"
#elif defined AUTUMN
#define TEXT "autumn"
#elif defined WINTER
#define TEXT "winter"
int main()
{
    std::cout<<TEXT<<std::endl;
}
