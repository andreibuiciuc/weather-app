#pragma once

#include "Protocol.h"
#include "../domain/Weather.h"

class Service {
private:
    Protocol* protocol{};
    // std::string jsonData{};

    Weather weather;

    void initProtocol(const std::string& option, const std::string &input);

    void parseJsonData(const std::string &jsonData);

public:
    Service() = default;

    void getWeather(const std::string &option, const std::string &input);

    ~Service() = default;
};

