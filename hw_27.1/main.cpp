#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
class FOREST{
    std::vector<std::vector<std::vector<std::string>>> homes {5,std::vector<std::vector<std::string>>(5,std::vector<std::string>(3))};
    void null_tree(){
        for(size_t i = 0;i<5;++i){
            for(size_t j = 0;j<5;++j){
                for(size_t k = 0;k<3;++k){
                    homes[i][j][k]="None";
                }
            }
        }
    };
    int neighbour_branch = -1;
    std::string elf_name="";
public:
    FOREST() {
        null_tree();
        std::cout<<"enter names of residents"<<std::endl;
        for (size_t i = 0; i < 5; ++i) {
            for (size_t j = 0; j < std::rand() % 3 + 3; ++j) {
                for (size_t k = 0; k < std::rand() % 2 + 2; ++k) {
                    std::cin >> homes[i][j][k];
                }
            }
        }
    }
    void check(){
        for (size_t i = 0; i < 5; ++i) {
            for (size_t j = 0; j < std::rand() % 3 + 3; ++j) {
                for (size_t k = 0; k < std::rand() % 2 + 2; ++k) {
                    std::cout<<homes[i][j][k]<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;std::cout<<std::endl;
        }
    }
    void get_branch(std::string name){
        for(size_t i = 0;i<5;++i){
            for(size_t j = 0;j<5;++j){
                for(size_t k = 0;k<3;++k){
                    if(homes[i][j][k] == name){
                        elf_name = name;
                        neighbour_branch = j;
                        return;
                    }
                }
            }
        }
        std::cout<<"There is no such elf here"<<std::endl;
    }
    void neighbours(){
        std::cout<<elf_name<<"'s neighbours: "<<std::endl;
        for(size_t i=0;i<5;++i){
            for(size_t j=0;j<3;++j){
                std::cout<<homes[i][neighbour_branch][j]<<" ";
            }
        }
    }




};

int main() {

    std::srand(unsigned (std::time(nullptr)));
    std::string elf;
    FOREST forest;
    std::cout<<"enter elf name"<<std::endl;
    std::cin>>elf;
    forest.get_branch(elf);
    forest.neighbours();
    forest.check();
}
