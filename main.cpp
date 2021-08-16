#include <iostream>
#include "gui/WeatherWindow.h"
#include "gui/MainWindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app{ argc, argv };

    Service service;

    WeatherWindow weatherWindow{ service };
    ChartWindow chartWindow;

    MainWindow mainWindow{ &weatherWindow, &chartWindow };
    mainWindow.show();

    return QApplication::exec();
}