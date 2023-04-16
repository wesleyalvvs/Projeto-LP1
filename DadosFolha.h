// Essa classe possui atributos comuns relacionados a folha de pagametno
#pragma once
#include "Data.h"

class DadosFolha
{
public:
    // construtor e destrutor
    DadosFolha();
    ~DadosFolha();

    // métodos get e set dos atributos

    void setSalarioBruto(double salarioBruto);
    void setSalarioLiquido(double salarioLiquido);
    void setCargaHoraria(int cargaHoraria);
    void setImpostoRenda(double impostoRenda);
    void setInss(double inss);
    void setHorasExtras(int horasExtras);
    void setDiasTrabalhados(int diasTrabalhados);
    void setNome(std::string nome);
    void setCodigoFunc(std::string codigoFunc);
    void setDataIngresso(Data dataIngresso);
    void setDataDemissao(Data dataDemissao);
    void setTipo(int tipo);
    void setSalario(double salario);
    void setDataFolha(Data data);

    double getSalarioBruto();
    double getSalarioLiquido();
    int getCargaHoraria();
    double getImpostoRenda();
    double getInss();
    double getHorasExtras();
    double getDiasTrabalhados();
    std::string getNome();
    std::string getCodigoFunc();
    Data getDataIngresso();
    Data getDataDemissao();
    int getTipo();
    double getSalario();
    Data getDataFolha();

private:
    // Declaração dos atributos comuns a folha de pagamento

    double salarioBruto;
    double salarioLiquido;
    int cargaHoraria;
    int horasExtras;
    int diasTrabalhados;
    double impostoRenda;
    double inss;
    std::string nome;
    std::string codigoFunc;
    Data dataIngresso;
    Data dataDemissao;
    int tipo;
    Data dataFolha;
    double salario;
};