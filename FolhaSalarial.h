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

    // m�todos get e set
    void setDataFolha(int mes, int ano);
    Data getDataFolha();

    // m�todos para obter infoma��es dos funcionarios da folha
    DadosFolha retornaDadosFunc(int indice);
    int retornaTamanhoVecDados();

    // m�todos que manipulam a folha de pagamento
    void retornaFuncAtivos(std::vector<Funcionario *> registros, int mes, int ano); // rever e adicionar arquivos
    void calcularFolhaMensal();                                                     // calcula a folha mensal de todos os funcion�rios do m�s que o usu�rio digitar
    void calculaFolhaAnual(std::vector<FolhaSalarial> folhaAnual, int ano);         // calcula a folha anual de todos os funcionarios do ano que o usuario digitar
    void exibeFolhaMensal();                                                        // exibe a folha do m�s que o usu�rio digitar
    void exibeFolhaAnual();                                                         // exibe a folha anual do ano escolhido pelo usu�rio
    void exibeFolhaFunc();                                                          // exibe a folha mensal de um funcion�rio (entrada do func. por c�digo ou nome)

private:
    std::vector<DadosFolha> dados;                 // vector que armazena os dados DE cada funcion�rios
    std::vector<Funcionario *> funcionariosAtivos; // vector com os funcion�rios ativos (� necess�rio para n�o incluir na folha mensal os funcion�rios que entraram no m�s seguinte ou que foram demitidos
    Data dataFolha;                                // Data da folha de pagamento
    double gastoAnual = 0;                         // Guarda o gasto anual da empresa
};
