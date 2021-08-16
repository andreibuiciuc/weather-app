#pragma once
#include <QWidget>
#include <Protocol.h>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QPushButton>
#include <Validator.h>
#include <Service.h>

class WeatherWindow: public QWidget {
Q_OBJECT

private:
    Validator *validator{};
    Service service;
    // Protocol *protocol{};

    // Graphical elements
    QLineEdit *lineEdit{};
    QRadioButton *searchCityButton{}, *searchZipButton{};
    QPushButton *searchButton{};

    void initWeatherWindow();

    void connectSignalsSlots();

public:
    explicit WeatherWindow(const Service& service);

    ~WeatherWindow() override = default;
};

