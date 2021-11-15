#include <iostream>

int jump (int n, int k=3){
    if(n == 0) { return 1; }

    int count=0;
    for(int i=1;i<=std::min(n,k);++i){
        count+= jump(n-i);
    }
    return count;

}
int main()
{
    int all_steps;
    std::cout<<"Input ladder length"<<std::endl;
    std::cin>>all_steps;
    std::cout<<jump(all_steps)<<std::endl;

    }