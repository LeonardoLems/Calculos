#ifndef NOTAFISCAL_H
#define NOTAFISCAL_H


class notaFiscal
{
public:



    void setCnpj(int num);
    void setDia(int num);
    void setValor(double num);
    void setNumero(long long num);
    void defaultNotas(bool confirmacao);

    int getCnpj(void);
    int getDia(void);
    long long getNumero(void);
    double getValor(void);

private:
    int cnpj,
        dia;
    double valor;
    long long numero;

};

#endif // NOTAFISCAL_H
