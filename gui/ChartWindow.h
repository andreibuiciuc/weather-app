#pragma once
#include <QWidget>

class ChartWindow: public QWidget {
Q_OBJECT

private:

    void initChartWindow();

    void connectSignalsSlots();

public:
    ChartWindow();

    ~ChartWindow() override = default;
};
