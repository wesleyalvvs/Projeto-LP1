//Implementação do costrutor/destrutor e dos métodos get e set

#include "DadosFolha.h"

DadosFolha::DadosFolha()
{
}

DadosFolha::~DadosFolha()
{
}

void DadosFolha::setSalarioBruto(double salarioBruto)
{
    this->salarioBruto = salarioBruto;
}

void DadosFolha::setSalarioLiquido(double salarioLiquido)
{
    this->salarioLiquido = salarioLiquido;
}

void DadosFolha::setCargaHoraria(int cargaHoraria)
{
    this->cargaHoraria = cargaHoraria;
}

void DadosFolha::setImpostoRenda(double impostoRenda)
{
    this->impostoRenda = impostoRenda;
}

void DadosFolha::setInss(double inss)
{
    this->inss = inss;
}

void DadosFolha::setHorasExtras(int horasExtras)
{
    this->horasExtras = horasExtras;
}

void DadosFolha::setDiasTrabalhados(int diasTrabalhados)
{
    this->diasTrabalhados = diasTrabalhados;
}

void DadosFolha::setNome(std::string nome)
{
    this->nome = nome;
}

void DadosFolha::setCodigoFunc(std::string codigoFunc)
{
    this->codigoFunc = codigoFunc;
}

void DadosFolha::setDataIngresso(Data dataIngresso)
{
    this->dataIngresso = dataIngresso;
}

void DadosFolha::setDataDemissao(Data dataDemissao)
{
    this->dataDemissao = dataDemissao;
}
void DadosFolha::setTipo(int tipo)
{
    this->tipo = tipo;
}
void DadosFolha::setSalario(double salario)
{
    this->salario = salario;
}

void DadosFolha::setDataFolha(Data data)
{
    this->dataFolha = data;
}

double DadosFolha::getSalarioBruto()
{
    return salarioBruto;
}

double DadosFolha::getSalarioLiquido()
{
    return salarioLiquido;
}

int DadosFolha::getCargaHoraria()
{
    return cargaHoraria;
}

double DadosFolha::getImpostoRenda()
{
    return impostoRenda;
}

double DadosFolha::getInss()
{
    return inss;
}

double DadosFolha::getHorasExtras()
{
    return horasExtras;
}

double DadosFolha::getDiasTrabalhados()
{
    return diasTrabalhados;
}

std::string DadosFolha::getNome()
{
    return nome;
}

std::string DadosFolha::getCodigoFunc()
{
    return codigoFunc;
}

Data DadosFolha::getDataIngresso()
{
    return dataIngresso;
}

Data DadosFolha::getDataDemissao()
{
    return dataDemissao;
}
int DadosFolha::getTipo()
{
    return tipo;
}
double DadosFolha::getSalario()
{
    return salario;
}
Data DadosFolha::getDataFolha()
{
    return dataFolha;
}
