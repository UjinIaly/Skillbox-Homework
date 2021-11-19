#include <iostream>
#include <fstream>

bool VALID_DATE(std::string *date) {
    int month = std::stoi(date->substr(3, 2));
    int day = std::stoi(date->substr(0, 2));
    int year = std::stoi(date->substr(6, 4));

    if (month > 12 || month < 1) {
        std::cout << "invalid input" << std::endl;
        return false;
    }

    if (day > 31 || day < 1) {
        std::cout << "invalid input" << std::endl;
        return false;
    } else {
        if ((month == 6 || month == 9 || month == 11) && day > 30) {
            std::cout << "invalid input" << std::endl;
            return false;
        }
        if (month == 2 && day > 28) {
            if (!(year % 4 == 0 && (!year % 100 == 0 || year % 400 == 0) && day == 29)) {
                std::cout << "invalid input" << std::endl;
                return false;
            }
        }
    }
    return true;

}

bool VALID_NAME(std::string name) {
    for (size_t i = 0; i < name.size(); ++i) {
        if (!(name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z')) {
            std::cout << "invalid input" << std::endl;
            return false;
        }
    }
    return true;
}

int main() {

    std::ofstream file;
    std::string name;
    std::string female;
    std::string date;
    double payment;
    file.setf(std::ios::showpoint);


    file.open("/home/ujin_ialy/Skillbox-Homework/hw_20.1/statement.txt", std::ios::app);
    while (true) {
        std::cout << "input name" << std::endl;
        std::cin >> name;
        if (VALID_NAME(name)) {
            std::cout << "input female" << std::endl;
            std::cin >> female;
            if (VALID_NAME(female)) {
                std::cout << "input date" << std::endl;
                std::cin >> date;
                if (VALID_DATE(&date)) {
                    std::cout << "input payment" << std::endl;
                    std::cin >> payment;
                    if (payment >= 0) {
                        file.width(9);
                        file << name << " ";
                        file.width(9);
                        file << female << " ";
                        file.width(10);
                        file << date << " ";
                        file.width(10);
                        file << payment << std::endl;
                    } else { continue; }
                } else { continue; }
            } else { continue; }
        } else { continue; }
        std::cout << "thanks for info" << std::endl;
    }


}
