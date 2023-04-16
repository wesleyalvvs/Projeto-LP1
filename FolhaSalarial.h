#pragma once
#include <vector>
#include <string>
#include "Funcionario.h"
#include "Data.h"
#include "DadosFolha.h"

class FolhaSalarial // Classe que guarda e manipula uma folha de pagamento
{
public:
    // Construtores e destrutor
    FolhaSalarial();
    virtual ~FolhaSalarial();

    // métodos get e set
    void setDataFolha(int mes, int ano);
    Data getDataFolha();

    // métodos para obter infomações dos funcionarios da folha
    DadosFolha retornaDadosFunc(int indice);
    int retornaTamanhoVecDados();

    // métodos que manipulam a folha de pagamento
    void retornaFuncAtivos(std::vector<Funcionario *> registros, int mes, int ano); // rever e adicionar arquivos
    void calcularFolhaMensal();                                                     // calcula a folha mensal de todos os funcionários do mês que o usuário digitar
    void calculaFolhaAnual(std::vector<FolhaSalarial> folhaAnual, int ano);         // calcula a folha anual de todos os funcionarios do ano que o usuario digitar
    void exibeFolhaMensal();                                                        // exibe a folha do mês que o usuário digitar
    void exibeFolhaAnual();                                                         // exibe a folha anual do ano escolhido pelo usuário
    void exibeFolhaFunc();                                                          // exibe a folha mensal de um funcionário (entrada do func. por código ou nome)

private:
    std::vector<DadosFolha> dados;                 // vector que armazena os dados DE cada funcionários
    std::vector<Funcionario *> funcionariosAtivos; // vector com os funcionários ativos (é necessário para não incluir na folha mensal os funcionários que entraram no mês seguinte ou que foram demitidos
    Data dataFolha;                                // Data da folha de pagamento
    double gastoAnual = 0;                         // Guarda o gasto anual da empresa
};
