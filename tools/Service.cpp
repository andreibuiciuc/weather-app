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

    json overall = json::parse(weatherData["weather"].dump());
    std::string main = overall[0]["main"];
    std::string desc = overall[0]["description"];

    json sys = json::parse(weatherData["sys"].dump());
    std::string country = sys["country"];

    std::string name = weatherData["name"];

    information info;
    info.name = name;
    info.country = country;
    info.main = main;
    info.desc = desc;

    this->weather = Weather(coord, temp, misc, info);
    std::string forecast = this->weather.getInfo();
    std::cout << forecast << std::endl;
}

void Service::getWeather(const std::string &option, const std::string &input) {
    this->initProtocol(option, input);
    std::string jsonData = this->protocol->getData();
    this->parseJsonData(jsonData);
}
