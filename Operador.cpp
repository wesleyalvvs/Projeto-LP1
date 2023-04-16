//Implementa os construtores e destrutor
#include "Operador.h"

Operador::Operador()
{

}
//Chama o construtor da classe Funcionario
Operador::Operador(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao)
: Funcionario(nome, endereco, telefone, cpf, rg, codigoFuncionario, salario, dataIngresso, dataDemissao, 1)
{

}

Operador::~Operador()
{

}