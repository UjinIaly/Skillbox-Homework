#include <iostream>
#include <exception>
#include <ctime>
#include <vector>
#include <cstdlib>

class Fish: public std::exception {
public:
    const char* what() const noexcept override {
        return "CAUGHT A FISH!!";
    }
};

class Boot: public std::exception {
public:
    const char* what() const noexcept override {
        return "CAUGHT Boot...\n";
    }
};

struct Field {
    Fish* fish = nullptr;
    Boot* boot = nullptr;
    bool nothing = true;
};

void Fill(Field *field) {
    int fishSector = std::rand() % 9;
    field[fishSector].fish = new Fish();
    field[fishSector].nothing = false;
    int count = 0;
    while(count<3){
       int bootSector = std::rand()%9;
       if(bootSector == fishSector){
           continue;
       }
       else if(field[bootSector].nothing){
           field[bootSector].boot = new Boot();
           ++count;
       }
       else {
           continue;
       }

    }
}

bool Fishing(Field *field, int sector){
    if (field[sector].fish != nullptr ) {
        throw Fish();
    }
    else if (field[sector].boot != nullptr ) {
        throw Boot();
    }
    return false;
}

int main(){
    std::srand(std::time(nullptr));
    Field field[9];

    Fill(field);

    bool nothing = true;
    int count = 1;
    while(nothing){
        std::cout << "Choose a sector for fishing(1:9): ";
        int sector;
        std::cin >> sector;

        try {
            Fishing(field, sector);
        }
        catch (const Fish& x) {
            std::cerr << "Cought exception: " << x.what();
        }
        catch (const Boot& x) {
            std::cerr << "Cought exception: " << x.what();
        }
        count++;
    }
}

