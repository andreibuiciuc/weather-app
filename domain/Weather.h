#pragma once
#include <string>

typedef struct {
    double longitude;
    double latitude;
}coordinates;

typedef struct {
    double temp;
    double tempFeelsLike;
    double tempMin;
    double tempMax;

}temperatures;

typedef struct {
    int pressure;
    int humidity;
    int visibility;
}miscellaneous;

class Weather {
private:
    coordinates coord{};
    temperatures temp{};
    miscellaneous misc{};
    std::string main;
    std::string desc;

public:
    Weather() = default;

    Weather(coordinates coord, temperatures temp, miscellaneous misc, const std::string &main, const std::string& desc);

    Weather(const Weather& obj);

    std::string getInfo();

    ~Weather() = default;
};

