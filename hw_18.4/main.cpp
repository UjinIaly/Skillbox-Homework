#include <iostream>
void evens_num(long long n, int &ans){
    if(n<1) {return;}

    if(n%2==0){
        ++ans;
    }
    n/=10;
    evens_num(n,ans);


}

int main() {
    long long number;
    std::cout<<"input your number"<<std::endl;
    std::cin>>number;
    int ans=0;

    evens_num(number,ans);
    std::cout<<ans;


}
