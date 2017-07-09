#include "mainwindow.h"
#include "dialogwindowhelp.h"

#include "ui_mainwindow.h"

#include <QtCore/qmath.h>
#include <QString>

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digits_pressed()));

    connect(ui->pushButton_sqrt, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_sin, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_cos, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_tg, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if ((ui->pushButton_plus->isChecked() && (!userIsTypingSecondNumber)) || (ui->pushButton_minus->isChecked() && (!userIsTypingSecondNumber)))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g', 12);
    }
    else
    {
        if (ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
           labelNumber = (ui->label->text() + button->text()).toDouble();
           newLabel = QString::number(labelNumber,'g', 12);
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    QString newLabel;
    newLabel = ui->label->text();

    if (newLabel.contains(".", Qt::CaseInsensitive)) ui->label->setText(trUtf8("Ошибка!"));
    else ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton *button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button -> text() == "√"){
        labelNumber = ui->label->text().toDouble();
        if (labelNumber < 0) ui->label->setText(trUtf8("Ошибка!"));
        else {labelNumber = sqrt(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
        }
    }

    if (button -> text() == "sin"){
        labelNumber = ui->label->text().toDouble();
        if(labelNumber > 1 && labelNumber < 1) ui->label->setText(trUtf8("Ошибка!"));
        else {labelNumber = qSin(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
        }
    }

    if (button -> text() == "cos"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = qCos(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
    }

    if (button -> text() == "tg"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = qTan(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
    QString newLabel;
    newLabel = ui->label->text();

    if (newLabel != "0"){

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);

    userIsTypingSecondNumber = false;

    newLabel.chop(1);
    ui->label->setText(newLabel);

    if (newLabel == "") ui->label->setText("0");
    }
}

void MainWindow::on_pushButton_clearFull_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelNumber, secondNum;
    QString newLabel;
    secondNum = ui->label->text().toDouble();

    QString tmp = " ";

    if (ui->pushButton_plus->isChecked())
    {
        if (firstNum == tmp.toDouble()) firstNum = 0;
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        if (firstNum == tmp.toDouble()) firstNum = 0;
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 12);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton *button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}

void MainWindow::on_pushButton_help_pressed()
{
    dialogWindowHelp winHelp(this);
    winHelp.setWindowTitle("Подсказка");
    winHelp.setFixedSize(401, 231);
    winHelp.exec();
}
