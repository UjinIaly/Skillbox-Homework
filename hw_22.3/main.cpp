#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<char,char> word1;
    std::map<char,char> word2;

    char first[100];
    char second[100];
    bool status= true;

    std::cout<<"input words"<<std::endl;
    std::cin>>first>>second;


    for(size_t i=0;first[i]>'a'&&first[i]<'z'||first[i]>'A'&&first[i]<'Z';++i){
        word1.insert(std::make_pair(first[i],first[i]));
        word2.insert(std::make_pair(second[i],second[i]));
    }

        std::map<char,char>::iterator it1 = word1.begin();
        for(std::map<char,char>::iterator it2 = word2.begin();it2!=word2.end();++it2){
            if(it1->first!=it2->first){
                status= false;
                break;
            }
            ++it1;

        }
        if(!status){
            std::cout<<"NO"<<std::endl;
        }
        else{
            std::cout<<"YES"<<std::endl;
        }









}
