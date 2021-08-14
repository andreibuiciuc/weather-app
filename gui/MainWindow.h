#pragma once
#include <QWidget>
#include <QPushButton>
#include "WeatherWindow.h"
#include "ChartWindow.h"

class MainWindow: public QWidget {
    Q_OBJECT

private:
    // Graphical elements
    WeatherWindow *weatherWindow;
    ChartWindow *chartWindow;
    QPushButton *weatherButton{}, *chartButton{};

    void initMainWindow();

    void connectSignalsSlots();

public:
    MainWindow(WeatherWindow* weatherWindow, ChartWindow* chartWindow);

    ~MainWindow() override = default;
};
