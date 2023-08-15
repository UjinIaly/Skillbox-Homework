#include <iostream>
#include <map>
#include <exception>

struct PRODUCTS{
    std::map <const std::string, const int> products = {
            {"keyboard",64},
            {"headphones",20},
            {"mouse", 15},
            {"hdmi",100},
            {"keyboard",64},
            {"phone",10},
            {"screen",12},
    };
};
struct BUCKET {
    std::map <const std::string, int>  bucket = {
            {"keyboard",0},
            {"headphones",0},
            {"mouse", 0},
            {"hdmi",0},
            {"keyboard",0},
            {"phone",0},
            {"screen",0},
    };
};

void list (const std::map<const std::string, int>& bucket){
    std::cout<<"your bucket:"<<std::endl;
    for(const auto & it : bucket){
        if (it.second != 0){
            std::cout<<it.first<<" - "<<it.second<<std::endl;
        }
    }
}
void add( std::map<const std::string, int>& bucket,
          std::map<const std::string, const int>& products,
          const std::string& product, int count){

    if (bucket.find(product)==bucket.end()){
        throw std::invalid_argument(product);
    }
    else if(count < 0 || count+bucket.find(product)->second > products.find(product)->second){
        throw std::invalid_argument("count");
    }
    bucket.find(product)->second+=count;

}
void remove( std::map<const std::string, int>& bucket,
             std::map<const std::string, const int>& products,
             const std::string& product, int count){
    if(count < 0 || bucket.find(product)->second - count < 0){
        throw std::invalid_argument("count");
        return;
    }
    else if (bucket.find(product)==bucket.end()){
        throw std::invalid_argument(product);
        return;
    }

    bucket.find(product)->second-=count;
}




int main() {
    BUCKET bucket;
    PRODUCTS products;
    std::string command;
    std::string product;
    int count;

    while(true){
        std::cout<<"What do you want to do?"<<std::endl;
        std::cin>>command;
        if(command == "list"){
            list(bucket.bucket);
        }
        else if(command == "add"){
            try {
                std::cout<<"which product you want to add?"<<std::endl;
                std::cin >> product;
                std::cout<<"how many?"<<std::endl;
                std::cin >> count;
                add(bucket.bucket, products.products,product, count);
            }
            catch(const std::exception& ex) {
                std::cerr<<"Exception caught - "<<ex.what()<<std::endl;
            }
        }
        else if(command == "remove"){
            try {
                std::cout << "which product you want to remove?" << std::endl;
                std::cin >> product;
                std::cout << "how many?" << std::endl;
                std::cin >> count;
                remove(bucket.bucket, products.products, product, count);
            }
            catch(const std::exception& ex) {
                std::cerr<<"Exception caught - "<<ex.what()<<std::endl;
            }
        }
        else if(command == "exit"){
            return 0;
        }
        else{
            std::cout<<"i don't know such command"<<std::endl;
        }
    }



}
