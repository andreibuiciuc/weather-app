#include <QMessageBox>
#include "WeatherWindow.h"
#include <iostream>

WeatherWindow::WeatherWindow(const Service& service) {
    this->service = service;
    this->initWeatherWindow();
    this->connectSignalsSlots();
}

void WeatherWindow::initWeatherWindow() {
    this->setWindowTitle("Weather Today");
    int x = (int)(this->width() * 0.75);
    int y = (int)(this->height() * 0.75);
    this->resize(x, y);

    auto* mainLayout = new QVBoxLayout{ this };
    auto* searchLayout = new QHBoxLayout{};

    auto* buttonGroup = new QGroupBox{tr("Choose search option: ")};
    this->searchCityButton = new QRadioButton{tr("City")};
    this->searchZipButton = new QRadioButton{tr("Zip code")};
    this->searchCityButton->setChecked(true);

    auto* buttonGroupLayout = new QVBoxLayout{};
    buttonGroupLayout->addWidget(this->searchCityButton);
    buttonGroupLayout->addWidget(this->searchZipButton);
    buttonGroupLayout->addStretch(1);
    buttonGroup->setLayout(buttonGroupLayout);

    searchLayout->addWidget(buttonGroup);

    this->lineEdit = new QLineEdit{};
    this->searchButton = new QPushButton{tr("Search")};
    searchLayout->addWidget(this->lineEdit);

    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(this->searchButton);
}

void WeatherWindow::connectSignalsSlots() {
    // Slot for search button
    QObject::connect(this->searchButton, &QPushButton::clicked, [this](){
        std::string input;
        std::string option;
        if(this->searchCityButton->isChecked()) {
            input = this->lineEdit->text().toStdString();
            option = "city";
            this->validator = new ValidatorCity{input};
        }
        else if(this->searchZipButton->isChecked()) {
            input = this->lineEdit->text().toStdString();
            option = "zipcode";
            this->validator = new ValidatorZip{input};
        }

        try {
            this->validator->validate();
        } catch(std::exception& e) {
            QMessageBox errorMessage;
            errorMessage.setText(e.what());
            errorMessage.show();
        }
        delete this->validator;
        this->service.getWeather(option, input);
    });
}

