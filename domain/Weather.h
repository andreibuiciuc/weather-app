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

typedef struct {
    std::string name;
    std::string country;
    std::string main;
    std::string desc;
}information;

class Weather {
private:
    coordinates coord{};
    temperatures temp{};
    miscellaneous misc{};
    information info{};

public:
    Weather() = default;

    Weather(coordinates coord, temperatures temp, miscellaneous misc, const information &info);

    Weather(const Weather& obj);

    std::string getInfo();

    ~Weather() = default;
};

