#pragma once
#include <QWidget>
#include <Protocol.h>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QPushButton>
#include <Validator.h>

class WeatherWindow: public QWidget {
Q_OBJECT

private:
    Validator *validator{};
    Protocol *protocol{};

    // Graphical elements
    QLineEdit *lineEdit{};
    QRadioButton *searchCityButton{}, *searchZipButton{};
    QPushButton *searchButton{};

    void initWeatherWindow();

    void connectSignalsSlots();

public:
    WeatherWindow();

    ~WeatherWindow() override = default;
};

