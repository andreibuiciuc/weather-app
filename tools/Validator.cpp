#include "Validator.h"

bool ValidatorCity::validate() {
    return true;
}

ValidatorCity::ValidatorCity(const std::string& str) : Validator(str) {

}

bool ValidatorZip::validate() {
    return true;
}

ValidatorZip::ValidatorZip(const std::string &str) : Validator(str) {

}
