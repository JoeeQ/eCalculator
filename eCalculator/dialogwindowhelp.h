#ifndef DIALOGWINDOWHELP_H
#define DIALOGWINDOWHELP_H

#include <QDialog>

namespace Ui { class dialogWindowHelp; }

class dialogWindowHelp : public QDialog
{
    Q_OBJECT

public:
    explicit dialogWindowHelp(QWidget *parent = 0);
    ~dialogWindowHelp();

private slots:
    void on_pushButton_pressed();

private:
    Ui::dialogWindowHelp *ui;
};

#endif // DIALOGWINDOWHELP_H
