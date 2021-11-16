#include <iostream>
#include <fstream>
enum sector{                                //
    ONE=1,
    TWO=2,
    THREE=3,
    FOUR=4,
    FIVE=5,
    SIX=6,
    SEVEN=7,
    EIGHT=8,
    NINE=9,
    TEN=10,
    ELEVEN=11,
    TWELVE=12,
    THIRTEEN=15,
};
int main() {


    std::string que;
    std::string ans;
    std::string cur_ans;
    int state = 0;
    int offset = 0;
    size_t audience = 0;
    size_t experts = 0;
    size_t temp=0;
    std::ifstream topic;
    std::ifstream reply;
    size_t cur_que=1;


    topic.open("/home/ujin_ialy/Skillbox-Homework/hw_19.5/questions.txt",std::ios::binary);
    reply.open("/home/ujin_ialy/Skillbox-Homework/hw_19.5/answers.txt",std::ios::binary);



    while(audience != 6 && experts != 6){
        std::cout<<"input offset"<<std::endl;
        std::cin>>offset;

        while(sector(offset) & state){                     //проверка: отвечал ли сектор
            ++offset;
            ++temp;
            if(temp==13){                                  //если все ответил, то опускаем все флаги  и идём снова по кругу
                for(size_t i = 0; i < 13; ++i){
                    state &= ~sector(i);
                }
            }
            if(offset==13){offset=1;}                      //если дошёл до 13 сектора во время проверки, переходим снова на 1
        }
        state|=sector(offset);                              //поднятие флага, если сектор ответил
        temp=0;
        size_t j=0;

        while(j!=cur_que && getline(topic,que)){              //считываем из файла нужный вопрос
            ++j;
        }

        j=0;
        std::cout<<que<<std::endl<<"Your answer: ";
        std::cin>>cur_ans;

        while(j!=cur_que && getline(reply,ans)){                //считываем из файла нужный ответ
            ++j;
        }

        if(cur_ans == ans){
            ++experts;
            std::cout<<"experts +1"<<std::endl;
        }
        else{
            ++audience;
            std::cout<<"audience +1"<<std::endl;
        }
        ++cur_que;
        if(cur_que==14){cur_que=1;}

    }
    if(experts==6){std::cout<<"congrats to experts!";}
    else {std::cout<<"congrats to audience!";}

}
