#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/html"});

    std::cout << r.text << std::endl;

    std::cout<<std::endl;
    size_t header_start = r.text.find("<h1>")+4;
    size_t header_end = r.text.find("</h1>");
    for(size_t i = header_start;i<header_end;++i ){
        std::cout<<r.text[i];
    }

}
