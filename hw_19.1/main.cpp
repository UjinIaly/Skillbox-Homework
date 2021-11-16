#include <iostream>
#include <fstream>
#include <vector>
int main() {
    std::ifstream words;
    std::string temp;

    std::string m_word;

    std::cout<<"input the word"<<std::endl;
    std::cin>>m_word;
    words.open("/home/ujin_ialy/Skillbox-Homework/hw_19.1/words.txt");
    size_t i=0;
    while(!words.eof()){
        words>>temp;
        if(temp==m_word) {
            ++i;
        }

    }
        std::cout<<i<<std::endl;
    file.close();


}
