#pragma once
#include "Funcionario.h"

class Gerente : public Funcionario // Herda da classe Funcionario e possui atributos que são exclusivos do Gerente
{
public:
//Construtores e destrutor
    Gerente();
    Gerente(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaSupervisao);
    virtual ~Gerente();
    //Metodo get e set
    void setAreaS(std::string areaSupervisao);
    std::string getAreaS();

private:
    std::string areaSupervisao;
};
