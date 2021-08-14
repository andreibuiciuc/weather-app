#include <iostream>
#include "gui/WeatherWindow.h"
#include "gui/MainWindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app{ argc, argv };

    WeatherWindow weatherWindow;
    ChartWindow chartWindow;

    MainWindow mainWindow{ &weatherWindow, &chartWindow };
    mainWindow.show();

    return QApplication::exec();
}