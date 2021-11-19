#include <iostream>
#include <ctime>
#include <fstream>

int main() {
    char action;
    int money[1000];
    int pull[6] = {100, 200, 500, 1000, 2000, 5000};
    std::ifstream file_in("money.bin", std::ios::binary);
    if (file_in.is_open()) {
        file_in.read((char *) money, sizeof(money));
        file_in.close();
    } else {
        for (size_t i = 0; i < 1000; ++i) {
            money[i] = 0;
        }
    }
    std::cout << "input the action: " << std::endl;
    std::cin >> action;

    if (action == '+') {
        for (size_t i = 0; i < 1000; ++i) {
            if (money[i] == 0) {
                money[i] = pull[std::rand() % 6];
            }
        }
        std::ofstream file_out("money.bin", std::ios::binary);
        file_out.write((char *) money, sizeof(money));
        file_out.close();
    } else if (action == '-') {
        int payment;
        std::cout << "input sum that you want to take off: " << std::endl;
        std::cin >> payment;
        if (payment % 100 != 0) {
            std::cout << "invalid sum" << std::endl;
            return 1;
        } else {
            for (size_t i = 5; i >= 0; --i) {
                for (size_t j = 0; j < 1000; ++j) {
                    if (pull[i] == money[j]) {
                        if(payment>=pull[i]) {
                            payment -= pull[i];
                            money[j] = 0;
                            if (payment == 0) {
                                std::cout << "well done" << std::endl;
                                std::ofstream file_out("money.bin", std::ios::binary);
                                file_out.write((char *) money, sizeof(money));
                                file_out.close();
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    } else {
        std::cout << " something goes wrong" << std::endl;
        return 1;
    }

}
