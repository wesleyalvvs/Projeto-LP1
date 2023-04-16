//Implementação dos construtores, destrutor e metodos get e set
#include "Pessoa.h"
#include "VerificaCaractere.h"
#include <stdexcept>
#include <exception>
#include <string>

Pessoa::Pessoa()
{
}

Pessoa::Pessoa(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg)
{
    setNome(nome);
    setEndereco(endereco);
    setTelefone(telefone);
    setCpf(cpf);
    setRg(rg);
}

Pessoa::~Pessoa()
{
}

void Pessoa::setNome(std::string nome)
{
    this->nome = nome;
}

void Pessoa::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}

void Pessoa::setTelefone(std::string telefone)
{
    this->telefone = telefone;
}

void Pessoa::setCpf(std::string cpf)
{
    this->cpf = cpf;
}

void Pessoa::setRg(std::string rg)
{
    this->rg = rg;
}

std::string Pessoa::getNome()
{
    return nome; 
}

Endereco Pessoa::getEndereco()
{
    return endereco;
}

std::string Pessoa::getTelefone()
{
    return telefone;
}
std::string  Pessoa::getcpf(){

    return cpf;
}

std::string  Pessoa::getRg(){
    
    return rg;
}

