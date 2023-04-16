#pragma once
#include "Funcionario.h"

class Diretor : public Funcionario // Herda os atributos de um funcion�rio e possui tamb�m atributos exlusivos de um diretor
{
public:
    // Construtores e destrutores
    Diretor();
    Diretor(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaSupervisao, std::string areaFormacao);
    virtual ~Diretor();
    // m�todos get e set
    void setAreaS(std::string areaSupervisao);
    void setAreaF(std::string areaFormacao);

    std::string getAreaS();
    std::string getAreaF();

private:
    // Atributos exclusivos de um diretor
    std::string areaSupervisao;
    std::string areaFormacao;
};
