#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string,std::string> directory;
    std::string command;
    while(command!="q"){
        std::cout<<"enter command"<<std::endl;
        std::cin>>command;
        if(command=="next"){
              std::map<std::string,std::string>::iterator ite = directory.begin();
              std::cout<<"<-"<<ite->second<<std::endl;
              directory.erase(ite);
        }
        else if(command=="list"){
            for(std::map<std::string,std::string>::iterator it = directory.begin();it!=directory.end();++it){
                std::cout<<"->"<<it->first<<std::endl;
            }
        }
        else {
            directory.insert(std::make_pair(command,command));
            std::cout<<"->"<<command<<std::endl;
        }
    }
}
