#include <iostream>

int jump(int k, int n) {
    if (n == 0)
        return 1;

    int n_count = 0;
    for (int i = 1; i <= std::min(k, n); ++i)
        n_count += jump(k, n - i);
    return n_count;
}
int main()
{
    int max_s;
    int all_steps;
    std::cout<<"Input max jump length and ladder length"<<std::endl;
    std::cin>>max_s>>all_steps;
    std::cout<<jump(max_s,all_steps)<<std::endl;



}