// Implementação dos construtores, destrutor e métodos get e set
#include "Diretor.h"
#include "VerificaCaractere.h"

Diretor::Diretor()
{
}
// Construtor dessa classe chama o contrutor da classe funcionário para evitar repetição de código
Diretor::Diretor(std::string nome, Endereco endereco, std::string telefone, std::string cpf, std::string rg, std::string codigoFuncionario, double salario, Data dataIngresso, Data dataDemissao, std::string areaSupervisao, std::string areaFormacao)
    : Funcionario(nome, endereco, telefone, cpf, rg, codigoFuncionario, salario, dataIngresso, dataDemissao, 3)
{
    this->areaSupervisao = areaSupervisao;
    this->areaFormacao = areaFormacao;
}

Diretor::~Diretor()
{
}
void Diretor::setAreaS(std::string areaSupervisao)
{
    this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaF(std::string areaFormacao)
{

    this->areaFormacao = areaFormacao;
}

std::string Diretor::getAreaS()
{
    return areaSupervisao;
}

std::string Diretor::getAreaF()
{
    return areaFormacao;
}
