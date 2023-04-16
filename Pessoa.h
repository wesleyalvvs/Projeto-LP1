#pragma once
#include <string>
#include "Endereco.h"

class Pessoa // Classe que possui atributos comuns as pessoas
{
public:
    // Construtores e destrutor
    Pessoa();
    Pessoa(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg);
    virtual ~Pessoa();
    // Metodos get e set dos atributos
    void setNome(std::string nome);
    void setEndereco(Endereco endereco);
    void setTelefone(std::string telefone);
    void setCpf(std::string cpf);
    void setRg(std::string rg);

    std::string getNome();
    Endereco getEndereco();
    std::string getTelefone();
    std::string getcpf();
    std::string getRg();

protected:
    // Atributos de uma pessoa
    std::string nome;
    std::string cpf;
    std::string rg;
    Endereco endereco;
    std::string telefone;
};
