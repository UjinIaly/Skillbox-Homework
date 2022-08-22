#include <iostream>
#include <map>
#include <string>

bool comp(std::string word1, std::string word2){
    if(word1.length()!=word2.length()){
        return false;
    }
    else {
        std::map<char,int> w1;
        std::map<char,int> w2;
        for(size_t i=0;i<word1.length();++i){
            w1.insert(std::pair<char,int>(word1[i],i));
            w2.insert(std::pair<char,int>(word2[i],i));
        }
        std::cout<<std::endl;
        std::map<char,int>::iterator it2 = w2.begin();
        for(std::map<char,int>::iterator it1 = w1.begin();it1!=w1.end();++it1){
            if(it1->first!=it2->first){return false;}
            ++it2;
        }
    }
    return true;
}

int main() {

    std::string word1;
    std::string word2;

    std::cout<<"input words"<<std::endl;
    std::cin>>word1>>word2;
    if(comp(word1,word2)){
        std::cout<<"YES"<<std::endl;
    }
    else{
        std::cout<<"NO"<<std::endl;
    }

}
