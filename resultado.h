#ifndef RESULTADO_H
#define RESULTADO_H

#include <QDialog>


namespace Ui {
class resultado;
}

class resultado : public QDialog
{
    Q_OBJECT

public:
    void setSomaCnpj(int num);
    void setSomaDia(int num);
    void setSomaValor(double num);
    void setSomaNumero(long long num);
    void defaultSomas(bool);


    explicit resultado(QWidget *parent = 0);
    ~resultado();

private:
    static long long somaNumero;
    static double somaValor;
    static int somaDia;
    static int somaCnpj;
    Ui::resultado *ui;
};

#endif // RESULTADO_H
