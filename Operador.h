#pragma once
#include "Funcionario.h"

class Operador : public Funcionario // Herda da classe Funcionario
{
public:
    // Construtores e destrutor
    Operador();
    Operador(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao);
    virtual ~Operador();

private:
};
