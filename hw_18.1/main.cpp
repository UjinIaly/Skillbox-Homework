#include <iostream>
#include <vector>
void foo(std::vector<int>& a,int b[])
  {
    for(size_t i=0;i<a.size();++i)
      {
        a[i]+=b[i];
        b[i]=a[i]-b[i];
        a[i]-=b[i];
      }

  for(size_t i=0;i<a.size();++i)
  {
    std::cout<<a[i]<<", ";
  }
  std::cout<<std::endl;
  for(size_t i=0;i<a.size();++i)
    {
      std::cout<<b[i]<<", ";
    }
  }
int main()
{

std::vector<int> a={2,4,6,8};
int b[]={1,2,3,4};
foo(a,b);

}