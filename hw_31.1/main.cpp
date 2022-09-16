#include <iostream>

class Toy{
private:
    std::string name;
public:
    Toy(std::string _name):name(_name){};
    Toy():Toy("unknown"){};

    //there may be everything, and not just simple functions and fields
    //then I focus on the fact that there can be complex manipulations with memory
};
class shared_ptr_toy{
private:
    Toy* subject = nullptr;
    size_t *count = new size_t(0);
public:
    shared_ptr_toy(){
        subject = new Toy();
        ++(*count);
    };

    shared_ptr_toy(std::string _name){
        subject = new Toy(_name);
        ++(*count);
    };

    shared_ptr_toy(shared_ptr_toy &toy):count(toy.count),subject(toy.subject){
        ++(*count);
    };

    shared_ptr_toy& operator= (shared_ptr_toy &toy){
        if(&toy != this){
            if(*count==1){
                delete count;
                delete subject;
            }
            else{(*count)--;}
            subject = toy.subject;
            count = toy.count;
            (*count)++;

        }
        return *this;
    }

    ~shared_ptr_toy(){
        if(*count == 1){
            delete subject;
            delete count;
        }
        else {
            *(count)--;
        }

    }
    size_t show_count(){
        return *count;
    }





};



int main() {
    shared_ptr_toy dog;
    std::cout<<dog.show_count()<<std::endl;
    shared_ptr_toy cat;
    std::cout<<cat.show_count()<<std::endl;
    cat = dog;
    std::cout<<dog.show_count()<<std::endl;
    std::cout<<cat.show_count()<<std::endl;








}
