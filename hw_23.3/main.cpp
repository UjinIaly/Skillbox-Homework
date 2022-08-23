#include <iostream>
#include <vector>

#define FILL(a,b,mass_over,mass_zero,all_count) for(int i=0;i<a;++i){std::cin>>b; \
all_count+=b;\
if(b>20){mass_over.push_back(i+1);}\
if(b==0){mass_zero.push_back(i+1);}\
}

#define WRITE(mass_over,zero_mass,all_count)\
std::cout<<"Переполненные вагоны:"<<std::endl;\
for(size_t i=0;i<mass_over.size();++i){std::cout<<mass_over[i]<<" ";}\
std::cout<<std::endl;\
std::cout<<"Пустые вагоны:"<<std::endl;\
for(size_t i=0;i<zero_mass.size();++i){std::cout<<zero_mass[i]<<" ";}\
std::cout<<std::endl<<"Общее число пассажиров:"<<all_count<<std::endl;


int main() {

    std::cout<<"let's start with filling wagons"<<std::endl;
    int count_passengers=0;
    std::vector<int> mass_over;
    std::vector<int> zero_mass;
    int all_count = 0;
    FILL(20,count_passengers,mass_over,zero_mass,all_count);

    WRITE(mass_over,zero_mass,all_count);








}
