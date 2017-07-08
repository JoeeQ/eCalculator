#include "dialogwindowhelp.h"
#include "ui_dialogwindowhelp.h"

dialogWindowHelp::dialogWindowHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogWindowHelp)
{
    ui->setupUi(this);
}

dialogWindowHelp::~dialogWindowHelp()
{
    delete ui;
}

void dialogWindowHelp::on_pushButton_pressed()
{
    QWidget::close();
}

