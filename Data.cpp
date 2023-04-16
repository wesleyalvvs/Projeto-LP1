//Implementação dos construtores, destrutor e get e set
#include "Data.h"
#include <string>
#include <iostream>
#include <iomanip>

Data::Data()
{
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::Data(int mes, int dia, int ano)
{
    this->setMes(mes);
    this->setDia(dia);
    this->setAno(ano);
}

Data::~Data()
{

}

void Data::setDia(int dia)
{
    this->dia = dia;
}

void Data::setMes(int mes)
{
    
    this->mes = mes;
}

void Data::setAno(int ano)
{
   
    this->ano = ano;
}

int Data::getDia()
{
    return dia;
}

int Data::getMes()
{
    return mes;
}

int Data::getAno()
{
    return ano;
}

void Data::toStringData() // Imprime a data já formatada
{
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << dia << '/' << std::setw( 2 ) << mes << '/' << ano;
}