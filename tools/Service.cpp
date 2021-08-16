#include "Service.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

void Service::initProtocol(const std::string &option, const std::string &input) {
    if(option == "city") {
        this->protocol = new ProtocolByCity{input};
    }
    else {
        this->protocol = new ProtocolByZipCode{input};
    }
}

void Service::parseJsonData(const std::string &jsonData) {
     std::cout << jsonData << std::endl;
     
     json weatherData = json::parse(jsonData);

     json coordData = json::parse(weatherData["coord"].dump());
     coordinates coord;
     coord.latitude = coordData["lon"];
     coord.longitude = coordData["lat"];

     json mainData = json::parse(weatherData["main"].dump());
     temperatures temp;
     miscellaneous misc;

     temp.temp = mainData["temp"];
     temp.tempFeelsLike = mainData["feels_like"];
     temp.tempMin = mainData["temp_min"];
     temp.tempMax = mainData["temp_max"];

     misc.humidity = mainData["humidity"];
     misc.pressure = mainData["pressure"];
     misc.visibility = weatherData["visibility"];

//     json info = json::parse(weatherData["weather"].dump());
//     std::string main = info["main"];
//     std::string desc = info["description"];
    std::string main = "asd";
    std::string desc = "qwe";

    this->weather = Weather(coord, temp, misc, main, desc);
    std::string forecast = this->weather.getInfo();
    std::cout << forecast << std::endl;
}

void Service::getWeather(const std::string &option, const std::string &input) {
    this->initProtocol(option, input);
    std::string jsonData = this->protocol->getData();
    this->parseJsonData(jsonData);
}
