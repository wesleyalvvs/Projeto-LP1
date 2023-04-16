#pragma once
#include <string>
#include "Data.h"
#include "Pessoa.h"

class Funcionario : public Pessoa // Herda os atributos e m�todos da classe Pessoa e possui atributos comuns a um funcion�rio
{
public:
    // construtores e destrutor
    Funcionario();
    Funcionario(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, int tipo);
    virtual ~Funcionario();
    // M�todos get e set
    void setSalario(double salario);
    void setCodigoFuncionario(std::string codigoFuncionario);
    void setDataIngresso(Data dataIngresso);
    void setDataDemissao(Data dataDemissao);

    int getTipo();
    double getSalario();
    std::string getCodigoFuncionario();
    Data getDataIngresso();
    Data getDataDemissao();

protected:
    std::string codigoFuncionario;
    int tipo; // Tipo do funcio�rio ex: tipo 1 == Operador
    double salario;
    Data dataIngresso;
    Data dataDemissao;
};