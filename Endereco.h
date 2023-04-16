#include <string>

#pragma once

class Endereco // Possui atributos comuns a um enre�o
{
public:
    // construtores e destrutores

    Endereco();
    Endereco(std::string rua, std::string numero, std::string cep, std::string cidade, std::string bairro, std::string estado);
    virtual ~Endereco();
    // m�todos get e set
    void setNumero(std::string numero);
    void setRua(std::string rua);
    void setCep(std::string cep);
    void setCidade(std::string cidade);
    void setBairro(std::string bairro);
    void setEstado(std::string estado);

    std::string getRua();
    std::string getNumero();
    std::string getCep();
    std::string getCidade();
    std::string getBairro();
    std::string getEstado();
    // Imprime o endere�o j� formatado
    void toStringEnd();

private:
    // Atributos comuns a um endere�o
    std::string rua;
    std::string numero;
    std::string cep;
    std::string cidade;
    std::string bairro;
    std::string estado;
};
