#pragma once
#include <string>

class Data // Essa clase possui atributos relacionados a datas
{
public:
    // construtores e destrutores
    Data();
    Data(int mes, int dia, int ano);
    virtual ~Data();

    // métodos get e set dos atributos

    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);

    int getDia();
    int getMes();
    int getAno();

    // metodo que imprime a data já formatada
    void toStringData();

private:
//Atributos comuns as datas
    int dia;
    int mes;
    int ano;
};