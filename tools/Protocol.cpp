#include "Protocol.h"
#include <curl/curl.h>
#include <memory>
#include <iostream>

//
// Protocol
//
Protocol::Protocol() {
    this->urlBase = "https://api.openweathermap.org/data/2.5/weather";
    this->key = "38cd042867216d9e28c2da4d5b747246";
}

std::string Protocol::getUrl() {
    return this->urlBase;
}

std::string Protocol::getKey() {
    return this->key;
}

std::size_t callback(const char *buffer, std::size_t size, std::size_t nmemb, void *ignore) {
    std::size_t realSize = size * nmemb;

    for(int i = 0; i < realSize; i ++) {
        std::cout << buffer[i];
    }

    return realSize;
}

void Protocol::getData() {
    // TODO
}

//
// Protocol by City Name
//
ProtocolByCity::ProtocolByCity(const std::string& cityName): Protocol(){
    this->cityName = cityName;
}

std::string ProtocolByCity::computeUrl() {
    return this->getUrl() + "?q=" + this->cityName + "&appid=" + this->getKey();
}

//
// Protocol By Zip Code
//
ProtocolByZipCode::ProtocolByZipCode(const std::string &zipcode) {
    this->zipcode = zipcode;
}

std::string ProtocolByZipCode::computeUrl() {
    return this->getUrl() + "?zip=" + this->zipcode + "&appid=" + this->getKey();
}

