#pragma once
#include <string>

class Protocol {
private:
    std::string urlBase;
    std::string key;

    std::string jsonData;

public:
    Protocol();

    std::string getKey();

    std::string getUrl();

    virtual std::string computeUrl() = 0;

    void getData();

    virtual ~Protocol() = default;
};

class ProtocolByCity: public Protocol {
private:
    std::string cityName;

public:
    explicit ProtocolByCity(const std::string& cityName);

    std::string computeUrl() override;

    ~ProtocolByCity() override = default;
};


class ProtocolByZipCode: public Protocol {
private:
    std::string zipcode;

public:
    explicit ProtocolByZipCode(const std::string& zipcode);

    std::string computeUrl() override;

    ~ProtocolByZipCode() override = default;
};

