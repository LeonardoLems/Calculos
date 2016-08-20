#include "conferencia.h"
#include "ui_conferencia.h"

conferencia::conferencia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conferencia)
{

    ui->setupUi(this);


}

conferencia::~conferencia()
{
    delete ui;
}
