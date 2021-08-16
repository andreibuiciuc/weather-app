#include <iostream>
#include "Weather.h"

Weather::Weather(coordinates coord, temperatures temp, miscellaneous misc, const std::string &main,
                 const std::string &desc) {
    this->coord = coord;
    this->temp = temp;
    this->misc = misc;
    this->main = main;
    this->desc = desc;
}

Weather::Weather(const Weather& obj) {
    this->coord = obj.coord;
    this->temp = obj.temp;
    this->misc = obj.misc;
    this->main = obj.main;
    this->desc = obj.desc;
}

std::string Weather::getInfo() {
    std::string info = this->main + " ----- " + this->desc + "\n";
    info += "Min: " + std::to_string(this->temp.tempMin - 272.15) + "\n";
    info += "Max: " + std::to_string(this->temp.tempMax - 272.15) + "\n";
    info += "Pressure: " + std::to_string(this->misc.pressure) + "\n";
    return info;
}
