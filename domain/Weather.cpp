#include <iostream>
#include <utility>
#include "Weather.h"

Weather::Weather(coordinates coord, temperatures temp, miscellaneous misc, const information &info) {
    this->coord = coord;
    this->temp = temp;
    this->misc = misc;
    this->info = info;
}

Weather::Weather(const Weather& obj) {
    this->coord = obj.coord;
    this->temp = obj.temp;
    this->misc = obj.misc;
    this->info = obj.info;
}

std::string Weather::getInfo() {
    std::string w = this->info.name + ", " + this->info.country + "\n";
    w += this->info.main + "\n";
    w += this->info.desc + "\n";
    w += "Min: " + std::to_string(this->temp.tempMin - 272.15) + "\n";
    w += "Max: " + std::to_string(this->temp.tempMax - 272.15) + "\n";
    w += "Pressure: " + std::to_string(this->misc.pressure) + "\n";
    return w;
}
