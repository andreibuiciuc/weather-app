#include <QVBoxLayout>
#include "MainWindow.h"

MainWindow::MainWindow(WeatherWindow* weatherWindow, ChartWindow* chartWindow) {
    this->weatherWindow = weatherWindow;
    this->chartWindow = chartWindow;

    this->initMainWindow();
    this->connectSignalsSlots();
}

void MainWindow::initMainWindow() {
    this->setWindowTitle("Weather App");
    int x = (int)(this->width() * 0.5);
    int y = (int)(this->height() * 0.5);
    this->resize(x, y);

    auto* mainLayout = new QVBoxLayout{ this };

    this->weatherButton = new QPushButton{ "Show me the weather" };
    this->chartButton = new QPushButton{ "Show last week report" };

    mainLayout->addWidget(this->weatherButton);
    mainLayout->addWidget(this->chartButton);
}

void MainWindow::connectSignalsSlots() {
    // Slot for weather button
    QObject::connect(this->weatherButton, &QPushButton::clicked, [this](){
        this->weatherWindow->show();
    });

    // Slot for chart button
    QObject::connect(this->chartButton, &QPushButton::clicked, [this](){
       this->chartWindow->show();
    });

}


