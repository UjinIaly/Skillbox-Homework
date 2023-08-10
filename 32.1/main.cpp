#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

int main() {
    nlohmann::json dict;
    dict["title"] = "Gifted";
    dict["Country"] = "USA";
    dict["Release_date"] = "07.04.2017";
    dict["Studio"] = "FilmNation Entertainment";
    dict["Author"] = "Tom Flynn";
    dict["Director"] = "Marc Webb";
    dict["Producer"] = "Karen Lunder";
    std::ofstream file("../record");
    file << dict;
}
