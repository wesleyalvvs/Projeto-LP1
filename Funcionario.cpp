//Implementação dos métodos get e set, assim como dos construtores e destrutor
#include "Funcionario.h"

Funcionario::Funcionario()
{
}

//Chama o construtor de Pessoa para evitar repetição de código
Funcionario::Funcionario(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, int tipo)
    : Pessoa(nome, endereco, telefone, cpf, rg)
{
    this->telefone = telefone;
    this->codigoFuncionario = codigoFuncionario;
    this->salario = salario;
    this->tipo = tipo;
    this->dataIngresso = dataIngresso;
    this->dataDemissao = dataDemissao;
}

Funcionario::~Funcionario()
{
}

void Funcionario::setSalario(double salario)
{
    this->salario = salario;
}

void Funcionario::setCodigoFuncionario(std::string codigoFuncionario)
{
    this->codigoFuncionario = codigoFuncionario;
}

void Funcionario::setDataIngresso(Data dataIngresso)
{
    this->dataIngresso = dataIngresso;
}

void Funcionario::setDataDemissao(Data dataDemissao)
{
    this->dataDemissao = dataDemissao;
}

double Funcionario::getSalario()
{
    return salario;
}

std::string Funcionario::getCodigoFuncionario()
{
    return codigoFuncionario;
}

Data Funcionario::getDataIngresso()
{
    return dataIngresso;
}

int Funcionario::getTipo()
{
    return tipo;
}

Data Funcionario::getDataDemissao()
{
    return dataDemissao;
}