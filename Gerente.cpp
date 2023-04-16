//Implementação dos métodos get e set assim como dos construtores e destrutor
#include "Gerente.h"
#include <stdexcept>
#include <exception>
#include "VerificaCaractere.h"

Gerente::Gerente()
{

}
//Chama o construtor de Funcionário para evitar a repetição de código
Gerente::Gerente(std::string nome, Endereco endereco, std::string telefone,  std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaSupervisao)
: Funcionario(nome, endereco, telefone, cpf, rg, codigoFuncionario, salario, dataIngresso, dataDemissao,  2)
{
    this->areaSupervisao = areaSupervisao;
}


Gerente::~Gerente()
{

}

void Gerente::setAreaS(std::string areaSupervisao)
{
    this->areaSupervisao = areaSupervisao;
}

std::string Gerente::getAreaS()
{
    return areaSupervisao;
}