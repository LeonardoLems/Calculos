#include "resultado.h"
#include "ui_resultado.h"
#include <QString>
int resultado::somaDia = 0;
int resultado::somaCnpj = 0;
double resultado::somaValor = 0;
long long resultado::somaNumero = 0;




resultado::resultado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultado)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(somaCnpj));
    ui->lineEdit_2->setText(QString::number(somaDia));
    ui->lineEdit_3->setText(QString::number(somaValor));
    ui->lineEdit_4->setText(QString::number(somaNumero));
}

resultado::~resultado()
{
    delete ui;


}
void resultado::setSomaCnpj(int num)
{
    somaCnpj += num;
}
void resultado::setSomaDia(int num)
{
    somaDia += num;
}

void resultado::setSomaValor(double num)
{
    somaValor += num;

}

void resultado::setSomaNumero(long long num)
{
    somaNumero += num;
}
void resultado::defaultSomas(bool confirmacao)
{
    if(confirmacao==true)
    {
        somaCnpj = 0;
        somaDia = 0;
        somaNumero = 0;
        somaValor = 0;
    }
}
