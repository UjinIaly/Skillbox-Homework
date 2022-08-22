#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string,int> queue;
    std::string command;
    int i=0;
    while(command!="q"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command=="next"){
              std::map<std::string,int>::iterator ite = queue.begin();
              std::cout<<"<-"<<ite->second<<std::endl;
              queue.erase(ite);
              --i;
        }
        else if(command=="list"){
            for(std::map<std::string,int>::iterator it = queue.begin();it!=queue.end();++it){
                std::cout<<"->"<<it->first<<std::endl;
            }
        }
        else {
            queue.insert(std::make_pair(command,i));
            std::cout<<"->"<<command<<std::endl;
            ++i;
        }
    }
}
