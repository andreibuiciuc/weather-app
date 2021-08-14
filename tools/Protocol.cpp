#include "Protocol.h"
#include <curl/curl.h>
#include <memory>

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

std::size_t callback(const char *buffer, std::size_t size, std::size_t nmemb, std::string *data) {
    std::size_t realSize = size * nmemb;

    for(int i = 0; i < realSize; i ++) {
        data->push_back(buffer[i]);
    }

    return realSize;
}

void Protocol::getData() {
    this->jsonData.clear();

    std::string url = this->computeUrl();

    CURL *curl = curl_easy_init();
    if(!curl) {
        throw std::exception();
    }

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->jsonData);

    CURLcode result = curl_easy_perform(curl);

    if(result != CURLE_OK) {
        throw std::exception();
    }

    curl_easy_cleanup(curl);
}

std::string Protocol::getJsonData() {
    return this->jsonData;
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

