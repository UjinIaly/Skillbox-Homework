#include <iostream>
#include <cpr/cpr.h>
#include <map>

std::string make_get_request(std::map<std::string,std::string> headers){

    if(headers.empty()){return "";}

    std::string request = "?";
    for(std::map<std::string,std::string>::iterator it = headers.begin();it!=headers.end();++it){
        request +=it->first;
        request +="=";
        request +=it->second;
        request +="&";
    }

    return request;

}

void send(std::string request,std::map<std::string,std::string> headers){
    if(request == "get"){
        std::string final_url= "http://httpbin.org/get" + make_get_request(headers);
        cpr::Response answer = cpr::Get(cpr::Url(final_url));
        std::cout<<"get request sent"<<std::endl;
        std::cout<<answer.text<<std::endl;
    }
    else if(request == "post"){
        cpr::Payload payload({});
        for(std::map<std::string,std::string>::iterator it = headers.begin();it!=headers.end();++it){
            cpr::Pair* p =  new cpr::Pair(it->first.c_str(),it->second.c_str());
            payload.Add(*p);
        }
        cpr::Response answer = cpr::Post(cpr::Url("http://httpbin.org/post"),cpr::Payload(payload));
        std::cout << "post request sent"<<std::endl;
        std::cout << answer.text << "";
    }
}


int main() {

    std::map<std::string,std::string> headers;
    std::string str;
    std::string header_key;
    std::string header_value;
    bool is_key = true;

    while(str!="exit"){

        if(is_key){std::cout<<"enter argument"<<std::endl;}
        else{std::cout<<"enter value"<<std::endl;}

        std::cin>>str;

        if(str == "get"){
            send("get",headers);
        }
        else if(str == "post"){
            send("post",headers);
        }
        else{
            if(is_key){
                header_key = str;
                is_key = false;
            }
            else{
                header_value = str;
                is_key = true;
                headers.insert(std::pair<std::string,std::string>(header_key,header_value));
            }
        }

    }

}
