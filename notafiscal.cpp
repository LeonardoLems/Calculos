#include "notafiscal.h"


void notaFiscal::defaultNotas(bool confirmacao)
{
    if(confirmacao==true)
    {
        cnpj =0;
        dia = 0;
        valor = 0;
        numero = 0;
    }
}

void notaFiscal::setCnpj(int num)
{
    cnpj = num;
}

void notaFiscal::setDia(int num)
{
    dia = num;
}

void notaFiscal::setValor(double num)
{
    valor = num;
}

void notaFiscal::setNumero(long long num)
{
    numero = num;
}


int notaFiscal::getCnpj(void)
{
    return cnpj;
}

int notaFiscal::getDia(void)
{
    return dia;
}

long long notaFiscal::getNumero(void)
{
    return numero;
}

double notaFiscal::getValor(void)
{
    return valor;
}
