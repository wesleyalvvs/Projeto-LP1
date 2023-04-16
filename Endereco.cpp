//Implementaçao dos Construtores, destrutor e métodos get e set
#include "Endereco.h"
#include "VerificaCaractere.h"
#include <iostream>

Endereco::Endereco()
{
}

Endereco::Endereco(std::string rua, std::string numero, std::string cep, std::string cidade, std::string bairro, std::string estado)
{
    setRua(rua);
    setNumero(numero);
    setCep(cep);
    setCidade(cidade);
    setBairro(bairro);
    setEstado(estado);
}

Endereco::~Endereco()
{
}

void Endereco::setNumero(std::string numero)
{
    this->numero = numero;
}

void Endereco::setRua(std::string rua)
{
    this->rua = rua;
}

void Endereco::setCep(std::string cep)
{
    
    this->cep = cep;
}

void Endereco::setCidade(std::string cidade)
{
    this->cidade = cidade;
}

void Endereco::setBairro(std::string bairro)
{
    this->bairro = bairro;
}

void Endereco::setEstado(std::string estado)
{
    this->estado = estado;
}

std::string Endereco::getRua()
{
    return rua;
}

std::string Endereco::getNumero()
{
    return numero;
}

std::string Endereco::getCep()
{
    return cep;
}

std::string Endereco::getCidade()
{
    return cidade;
}

std::string Endereco::getBairro()
{
    return bairro;
}

std::string Endereco::getEstado()
{
    return estado;
}
// Imprmime o endereço já formatado
void Endereco::toStringEnd()
{
    std::cout << "Rua: " << rua << ", número: " << numero << ", CEP: " << cep << ", Bairro: " << bairro << ", Cidade: " << cidade << ", Estado: " << estado << std::endl;
}