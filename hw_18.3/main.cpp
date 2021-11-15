#include <iostream>

void jump(size_t max_s,size_t all_steps,int nj,size_t l,int *my_mass,int& num_jmp)
{
    for(int i=1; i<=max_s && l+i<=all_steps; ++i)
    {
        my_mass[nj]=i;
        if(l+i==all_steps)
        {
            num_jmp++;
            return;
        }
        jump(max_s,all_steps,nj+1,l+i,my_mass,num_jmp);
    }
}
int main()
{
    size_t max_s;
    size_t all_steps;
    std::cout<<"Input max jump length and ladder length"<<std::endl;
    std::cin>>max_s>>all_steps;
    int *my_mass=new int[all_steps];
    int num_jmp=0;
    jump(max_s,all_steps,0,0,my_mass,num_jmp);
    std::cout<<num_jmp<<std::endl;
    delete[] my_mass;
}