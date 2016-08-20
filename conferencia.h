#ifndef CONFERENCIA_H
#define CONFERENCIA_H

#include <QDialog>
#include"mainwindow.h"

namespace Ui {
class conferencia;
}

class conferencia : public QDialog
{
    Q_OBJECT

public:
    explicit conferencia(QWidget *parent = 0);
    ~conferencia();

private:

    Ui::conferencia *ui;
};

#endif // CONFERENCIA_H
