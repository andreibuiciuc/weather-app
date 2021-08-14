#include "ChartWindow.h"

ChartWindow::ChartWindow() {
    this->initChartWindow();
    this->connectSignalsSlots();
}

void ChartWindow::initChartWindow() {
    int x = (int)(this->width() * 0.75);
    int y = (int)(this->height() * 0.75);
    this->resize(x, y);
}

void ChartWindow::connectSignalsSlots() {

}
