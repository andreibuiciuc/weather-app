#pragma once
#include <string>

class Validator {
private:
    std::string str;

public:
    explicit Validator(const std::string& str) {
        this->str = str;
    }

    virtual bool validate() = 0;

    virtual ~Validator() = default;
};

class ValidatorCity: public Validator {
public:
    explicit ValidatorCity(const std::string& str);

    bool validate() override;

    ~ValidatorCity() override = default;
};

class ValidatorZip: public Validator {
public:
    explicit ValidatorZip(const std::string& str);

    bool validate() override;

    ~ValidatorZip() override = default;
};
