#include <iostream>
#include <vector>

template <typename Type, typename Value>
struct Data
{
public:
    Type key;
    Value value;

    Data(){};
    Data(Type key, Value value) : key(key), value(value){};
};
template <typename Type, typename Value>
class Base{

    std::vector<Data<Type, Value>> mass;

public:
    void print(){
        if (mass.empty())
        {
            std::cout << "Base is empty.\n";
            return;
        }
        std::cout << "Registry base:\n";
        for (auto it = mass.begin(); it != mass.end(); ++it)
        {
            std::cout << " + " << it->key << " : " << it->value << "\n";
        }
    }

    void add(Type key, Value value)
    {
        auto *data = new Data<Type, Value>(key, value);
        this->mass.push_back(*data);
        std::cout << "Element " << data->key << " : " << data->value << "\" is added.\n";
        delete data;
    }

    void remove(Type key)
    {
        int removeCount {0};
        for (auto it = mass.begin(); it != mass.end();)t
        {
            if (it->key == key)
            {
                std::cout << "Element \"" << it->key << " : " << it->value << "\" is removed.\n";
                it = mass.erase(it);
                ++removeCount;
            }
            else
            {
                ++it;
            }
        }
        if (removeCount == 0)
            std::cout << "Key \"" << key << "\" is not found.\n";
    }

    Data<Type, Value> *find(Type key) {
        for (size_t i = 0; i < mass.size(); ++i)
        {
            if (mass[i].key == key) return &mass[i];
        }
        std::cout << "Key is not found.\n";
        return nullptr;
    }


};

int main(){
    std::cout << "STRING\n";
    Base<std::string, int> string;

    string.add("some", 34);
    string.add("some", 34);
    string.print();

    string.remove("some");
    string.print();

    string.add("anth", 34);

    string.remove("anth");
    string.print();

    string.remove("anth");
    string.print();

    string.add("some", 34);
    string.add("anth", 34);
    string.add("whatever", 7);
    string.print();
    auto findResult = string.find("whatever");
    std::cout << findResult->key << " is found.\n";

    std::cout << "INT\n";
    Base<int, double> numbers;

    numbers.add(1, 34.7);
    numbers.add(2, 34.3);
    numbers.print();

    Data<int, double> d2(1, 34.8);
    numbers.add(1,34.8);
    numbers.print();

    numbers.remove(1);
    numbers.print();

    numbers.remove(2);
    numbers.print();

    numbers.remove(2);
    numbers.print();

    numbers.add(1, 34.1);
    numbers.add(2, 34.7);
    numbers.add(3, 7.4);
    numbers.print();
    auto findResult2 = numbers.find(3);
    std::cout << findResult2->key << " is found.\n";

    return 0;
}

