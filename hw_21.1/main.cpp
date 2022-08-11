#include <iostream>
#include <fstream>

struct base{
    std::string name=" ";
    std::string surname=" ";
    std::string date=" ";
    double payment=0;
};
bool VALID_DATE(base *person) {
    int month = std::stoi(person->date.substr(3, 2));
    //int month = (person->name[3] - '0')*10 + person->name[4]-'0';
    int day = std::stoi(person->date.substr(0, 2));
    //int day = (person->name[0] - '0') * 10 +person->name[1]-'0';
    int year = std::stoi(person->date.substr(6, 4));
    //int year = (person->name[6]-'0') * 10 + person->name[9]-'0';

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

bool VALID_NAME(base *person) {
    for (size_t i = 0; i < person->name.size(); ++i) {
        if (!(person->name[i] >= 'A' && person->name[i] <= 'Z' || person->name[i] >= 'a' && person->name[i] <= 'z')) {
            std::cout << "invalid input" << std::endl;
            return false;
        }
    }
    return true;
}

int main() {

    std::ofstream wfile;
    std::ifstream rfile;
    base person;
    std::string command;

    wfile.setf(std::ios::showpoint);




    wfile.open("/home/iwaly/Skillbox-Homework/hw_21.1/statement.txt", std::ios::app);
    rfile.open("/home/iwaly/Skillbox-Homework/hw_21.1/statement.txt", std::ios::app);
    while (true) {
        std::cout<<"enter command"<<std::endl;
        std::cin >> command;
        if (command == "list") {
            rfile.seekg(0, std::ios::beg);
            std::cout << rfile.tellg() << std::endl;
            while (!rfile.eof()) {
                rfile >> person.name;
                rfile >> person.surname;
                rfile >> person.date;
                rfile >> person.payment;
                std::cout << person.name << " " << person.surname << " " << person.date << " " << person.payment
                          << std::endl;

            }
        }
        if (command == "add") {
            std::cout << "input name" << std::endl;
            std::cin >> person.name;
            if (VALID_NAME(&person)) {
                std::cout << "input surname" << std::endl;
                std::cin >> person.surname;
                if (VALID_NAME(&person)) {
                    std::cout << "input date" << std::endl;
                    std::cin >> person.date;
                    if (VALID_DATE(&person)) {
                        std::cout << "input payment" << std::endl;
                        std::cin >> person.payment;
                        if (person.payment >= 0) {
                            wfile.width(9);
                            wfile << person.name << " ";
                            wfile.width(9);
                            wfile << person.surname << " ";
                            wfile.width(10);
                            wfile << person.date << " ";
                            wfile.width(10);
                            wfile << person.payment << std::endl;
                        } else { continue; }
                    } else { continue; }
                } else { continue; }
            } else { continue; }
            std::cout << "thanks for info" << std::endl;
        }
    }
    wfile.close();
    rfile.close();


}