#pragma once
#include <string>

class Protocol {
private:
    std::string urlBase;
    std::string key;

    std::string jsonData;

    virtual std::string computeUrl() = 0;

    friend std::size_t callback(const char *buffer, std::size_t size, std::size_t nmemb, std::string *data);

public:
    Protocol();

    std::string getKey();

    std::string getUrl();

    std::string getJsonData();

    void getData();

    virtual ~Protocol() = default;
};

class ProtocolByCity: public Protocol {
private:
    std::string cityName;

    std::string computeUrl() override;

public:
    explicit ProtocolByCity(const std::string& cityName);

    ~ProtocolByCity() override = default;
};


class ProtocolByZipCode: public Protocol {
private:
    std::string zipcode;

    std::string computeUrl() override;

public:
    explicit ProtocolByZipCode(const std::string& zipcode);

    ~ProtocolByZipCode() override = default;
};

