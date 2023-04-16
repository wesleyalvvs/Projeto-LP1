#pragma once
#include "Funcionario.h"

class Presidente : public Funcionario // Classe herda de Funcionario e possui alguns atributos especiíicos do presidente
{
public:
    // Construtores e destrutor
    Presidente();
    Presidente(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaFormacao, std::string formacaoAcademica);
    virtual ~Presidente();
    // Metodos get e set dos atributos
    void setAreaFormacao(std::string areaFormacao);
    void setFormacaoAcademica(std::string formacaoAcademica);

    std::string getAreaFormacao();
    std::string getFormacaoAcademica();

private:
    // Atributos exclusivos do presidente
    std::string areaFormacao;
    std::string formacaoAcademica;
};
