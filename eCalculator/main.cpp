#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow calculator;
    calculator.setWindowTitle("eCalculator");
    calculator.setFixedSize(363,420);
    calculator.show();

    return app.exec();
}
