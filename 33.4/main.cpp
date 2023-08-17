#include <iostream>
#include <vector>

template<typename T>
void input(std::vector<T> vec){
    T number;
    for(size_t i = 0;i<8;++i){
        std::cin>>number;
        vec.push_back(number);
    }
    T result = 0;
    size_t i;
    for(i =0;i<vec.size();++i){
        result+=vec[i];
    }
    result/=i;
    std::cout<<"result - "<<result<<std::endl;
}
int main() {
    std::vector<int> vec;
    input(vec);

}
