//Implementação dos construtores, destrutor e os metodos get e set
#include "Presidente.h"
#include <stdexcept>
#include <exception>
#include "VerificaCaractere.h"

Presidente::Presidente()
{

}
//Chama o construtor de funcionário para evitar a repetição de código
Presidente::Presidente(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaFormacao, std::string formacaoAcademica)
: Funcionario(nome, endereco, telefone, cpf, rg, codigoFuncionario, salario, dataIngresso, dataDemissao,  4)
{
    this->areaFormacao = areaFormacao;
    this->formacaoAcademica = formacaoAcademica;
}

Presidente::~Presidente()
{

}

void Presidente::setAreaFormacao(std::string areaFormacao)
{
   
    this->areaFormacao = areaFormacao;
}

void Presidente::setFormacaoAcademica(std::string formacaoAcademica)
{
    this->formacaoAcademica = formacaoAcademica;
}

std::string Presidente::getAreaFormacao()
{
    return areaFormacao;
}

std::string Presidente::getFormacaoAcademica()
{
    return formacaoAcademica;
}