// calcula a folha salarial de todos os funcionarios de um determinando m�s

#include "FolhaSalarial.h"
#include "Gerenciador.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Funcionario.h"
#include <iomanip>

// constantes do Imposto de Renda
//#define FAIXA_IMP1 -> n�o � necess�rio, pois � isento
#define FAIXA_IMP2 0.075
#define FAIXA_IMP3 0.15
#define FAIXA_IMP4 0.225
#define FAIXA_IMP5 0.275

#define VALOR_FAIXA_IMP1 1903.98
#define VALOR_FAIXA_IMP2 2826.65
#define VALOR_FAIXA_IMP3 3751.05
#define VALOR_FAIXA_IMP4 4664.68

// constantes do INSS
#define FAIXA_INSS1 0.075
#define FAIXA_INSS2 0.09
#define FAIXA_INSS3 0.12
#define FAIXA_INSS4 0.14

#define VALOR_FAIXA_INSS1 1212.00
#define VALOR_FAIXA_INSS2 2427.35
#define VALOR_FAIXA_INSS3 3641.03
#define VALOR_FAIXA_INSS4 7087.22

using namespace std;

// Implementa��o do construtor, destrutor e m�todos get e set
FolhaSalarial::FolhaSalarial()
{
}

FolhaSalarial::~FolhaSalarial()
{
}

void FolhaSalarial::setDataFolha(int mes, int ano)
{

    dataFolha = Data(mes, 1, ano);
}

Data FolhaSalarial::getDataFolha()
{
    return dataFolha;
}
// Retorna informa��es do vetor de dados
DadosFolha FolhaSalarial::retornaDadosFunc(int indice)
{
    return dados[indice];
}

int FolhaSalarial::retornaTamanhoVecDados()
{
    return dados.size();
}
// Fun��o para verificar os funcio�rios ativos de um determinado m�s
void FolhaSalarial::retornaFuncAtivos(std::vector<Funcionario *> registros, int mes, int ano)
{
    int cont = 0;
    for (int i = 0; i < registros.size(); i++)
    {
        cont = 0;
        // se o funcion�rio n�o foi demitido ou se o funcion�rio est� na empresa at� o presente m�s e ano
        if (registros[i]->getDataDemissao().getMes() != 0 && registros[i]->getDataDemissao().getMes() <= mes && registros[i]->getDataDemissao().getAno() <= ano)
        {

            cont++;
        }

        if (registros[i]->getDataIngresso().getAno() > ano)

        {
            cont++;
        }

        if (registros[i]->getDataIngresso().getAno() == ano)
        {
            if (registros[i]->getDataIngresso().getMes() > mes)
            {
                cont++;
            }
        }

        // if para garantir que n�o teremos funcion�rios repetidos em FuncAtivos

        if (cont == 0)
        {
            if (registros[i]->getTipo() == 1)
            {
                // Adiciona o funcion�rio - operador
                funcionariosAtivos.push_back((Operador *)registros[i]);
            }
        }

        if (cont == 0)
            if (registros[i]->getTipo() == 2)
            {
                // Adiciona o funcion�rio - Gerente
                funcionariosAtivos.push_back((Gerente *)registros[i]);
            }

        if (cont == 0)
        {
            if (registros[i]->getTipo() == 3)
            {
                // Adiciona o funcion�rio - Diretor
                funcionariosAtivos.push_back((Diretor *)registros[i]);
            }
        }

        if (cont == 0)
        {
            if (registros[i]->getTipo() == 4)
            {
                // Adiciona o funcion�rio - presidente
                funcionariosAtivos.push_back((Presidente *)registros[i]);
            }
        }
    }
    setDataFolha(mes, ano);
}

void FolhaSalarial::calcularFolhaMensal() // Calcula a folha mensal
{
    int cargaHoraria;
    double impostoRenda, inss;
    DadosFolha dado;

    srand(time(NULL));

    for (int i = 0; i < funcionariosAtivos.size(); i++)
    {
        int horaExtra = (rand() % 10);            // esta instru��o guarda em 'horaExtra' um valor aleat�rio entre 0 e 10 (horas)
        int diasTrabalhados = 12 + (rand() % 14); // esta instru��o guarda em 'diasTrabalhados' um valor aleat�rio entre 0 e 26 (dias)

        double valorHora = funcionariosAtivos[i]->getSalario() / 208; // Sal�rio dividido pelo total de horas trabalhadas no M�s (considerando 26 dias trabalhados (m�ximo) e 8 horas de trabalho por dia);

        double salariomensal = (funcionariosAtivos[i]->getSalario() / 30) * diasTrabalhados;

        double salarioBruto = salariomensal + (horaExtra * (valorHora * 2)); // soma ao Sal�rio do funcion�rio o valor relativo � hora extra

        double salarioLiquido = salarioBruto;

        // impostos do Imposto de Renda
        if (salarioBruto <= VALOR_FAIXA_IMP1)
        {
            impostoRenda = 0; // isento
        }
        if (salarioBruto > VALOR_FAIXA_IMP1 && salarioBruto <= VALOR_FAIXA_IMP2)
        {
            impostoRenda = salarioBruto * FAIXA_IMP2; // imposto de 7.5%
        }
        if (salarioBruto > VALOR_FAIXA_IMP2 && salarioBruto <= VALOR_FAIXA_IMP3)
        {
            impostoRenda = salarioBruto * FAIXA_IMP3; // imposto de 15.0%
        }
        if (salarioBruto > VALOR_FAIXA_IMP3 && salarioBruto <= VALOR_FAIXA_IMP4)
        {
            impostoRenda = salarioBruto * FAIXA_IMP4; // imposto de 22.5%
        }
        if (salarioBruto > VALOR_FAIXA_IMP4)
        {
            impostoRenda = salarioBruto * FAIXA_IMP5; // imposto de 27.5%
        }

        // impostos do INSS
        if (salarioBruto <= VALOR_FAIXA_INSS1) // imposto de 7.5% (faixa 1)
        {
            inss = salarioBruto * FAIXA_INSS1;
        }
        if (salarioBruto > VALOR_FAIXA_INSS1 && salarioBruto <= VALOR_FAIXA_INSS2) // imposto de 9.0% (faixa 2)
        {
            inss = (FAIXA_INSS1 * VALOR_FAIXA_INSS1) + ((salarioBruto - VALOR_FAIXA_INSS1) * FAIXA_INSS2);
        }
        if (salarioBruto > VALOR_FAIXA_INSS2 && salarioBruto <= VALOR_FAIXA_INSS3) // imposto de 12.0% (faixa 3)
        {
            inss = (FAIXA_INSS1 * VALOR_FAIXA_INSS1) + ((VALOR_FAIXA_INSS2 - VALOR_FAIXA_INSS1) * FAIXA_INSS2) + ((salarioBruto - VALOR_FAIXA_INSS2) * FAIXA_INSS3);
        }
        if (salarioBruto > VALOR_FAIXA_INSS3 && salarioBruto < VALOR_FAIXA_INSS4) // imposto de 14.0% (faixa 4)
        {
            inss = (FAIXA_INSS1 * VALOR_FAIXA_INSS1) + ((VALOR_FAIXA_INSS2 - VALOR_FAIXA_INSS1) * FAIXA_INSS2) + ((VALOR_FAIXA_INSS3 - VALOR_FAIXA_INSS2) * FAIXA_INSS3) + ((salarioBruto - VALOR_FAIXA_INSS4) * FAIXA_INSS4);
        }
        if (salarioBruto > VALOR_FAIXA_INSS4) // imposto de 14.0% (faixa 4)
        {
            inss = (FAIXA_INSS1 * VALOR_FAIXA_INSS1) + ((VALOR_FAIXA_INSS2 - VALOR_FAIXA_INSS1) * FAIXA_INSS2) + ((VALOR_FAIXA_INSS3 - VALOR_FAIXA_INSS2) * FAIXA_INSS3) + ((VALOR_FAIXA_INSS4 - VALOR_FAIXA_INSS3) * FAIXA_INSS4);
        }
        // Adiciona as informa��es de cada funcion�rio dentro do vector de dados ap�s os calculos de sal�rio, horas trabalhadas...
        dado.setNome(funcionariosAtivos[i]->getNome());
        dado.setCodigoFunc(funcionariosAtivos[i]->getCodigoFuncionario());
        dado.setTipo(funcionariosAtivos[i]->getTipo());
        dado.setSalario(funcionariosAtivos[i]->getSalario());
        dado.setDataIngresso(funcionariosAtivos[i]->getDataIngresso());
        dado.setSalarioBruto(salarioBruto);
        dado.setSalarioLiquido(salarioBruto - impostoRenda - inss);
        dado.setCargaHoraria((diasTrabalhados * 8) + horaExtra);
        dado.setImpostoRenda(impostoRenda);
        dado.setInss(inss);
        dado.setHorasExtras(horaExtra);
        dado.setDiasTrabalhados(diasTrabalhados);

        dados.push_back(dado);
    }
}

void FolhaSalarial::exibeFolhaMensal() // Exibe a folha mensal j� calculada
{
    cout << "Folha referente ao m�s " << dataFolha.getMes() << " do ano de " << dataFolha.getAno() << endl
         << endl;

    for (int i = 0; i < dados.size(); i++)
    {
        cout << "Nome: " << dados[i].getNome() << "    ";

        cout << "-    C�digo do Funcion�rio: " << dados[i].getCodigoFunc() << endl;

        cout << "Sal�rio bruto: R$ " << dados[i].getSalarioBruto() << ", ";

        cout << "Descontos dos Impostos: R$ " << (dados[i].getImpostoRenda() + dados[i].getInss()) << ", ";

        cout << "S�lario l�quido: R$ " << dados[i].getSalarioLiquido() << endl;

        // cout << "Data de ingresso: ";
        // dados[i].getDataIngresso().toStringData();

        cout << endl;
    }
}

void FolhaSalarial::exibeFolhaFunc() // Exibe apenas a folha de de um funcion�rio de um determinado m�s buscando pelo nome ou c�dido do funcion�rio
{
    string busca;

    cout << "Digite o c�digo do funcion�rio ou nome completo do funcion�rio: ";
    fflush(stdin);
    getline(cin, busca);

    for (int i = 0; i < dados.size(); i++)
    {
        if (dados[i].getNome().compare(busca) == 0 || dados[i].getCodigoFunc().compare(busca) == 0) // Apenas quando achar o funion�rio correto o programa exibe-o
        {
            cout << "Nome: " << dados[i].getNome() << endl;

            cout << "Cargo: ";
            if (dados[i].getTipo() == 1)
                cout << "Operador" << endl;
            if (dados[i].getTipo() == 2)
                cout << "Gerente" << endl;
            if (dados[i].getTipo() == 3)
                cout << "Diretor" << endl;
            if (dados[i].getTipo() == 4)
                cout << "Presidente" << endl;

            // cout << "Sal�rio base: R$ " << dados[i].getSalario() << endl;

            cout << "Sal�rio bruto: R$ " << dados[i].getSalarioBruto() << endl;

            cout << "Descontos dos Impostos: R$ " << (dados[i].getImpostoRenda() + dados[i].getInss()) << endl;

            cout << "S�lario l�quido: R$ " << dados[i].getSalarioLiquido() << endl;

            // cout << "Carga hor�ria: " << dados[i].getCargaHoraria() << " horas" << endl;

            cout << "Desconto do imposto de renda: " << dados[i].getImpostoRenda() << endl;

            cout << "Desconto do INSS: " << dados[i].getInss() << endl;

            // cout << "Horas extras: " << dados[i].getHorasExtras() << endl;

            // cout << "Dias trabalhados: " << dados[i].getDiasTrabalhados() << endl;
            break;
        }
    }
}

void FolhaSalarial::calculaFolhaAnual(std::vector<FolhaSalarial> folhaMensal, int ano) // Calcula a folha anual solicitada pelo usu�rio
{
    DadosFolha dado;

    double somaSalarioBruto = 0;
    double somaSalarioLiquido = 0;
    double somaInss = 0;
    double somaImpostoRenda = 0;
    int somaCargaHoraria = 0;
    int somaHorasExtras = 0;
    int somaDiasTrabalhados = 0;

    int mes = 1;

    while (1)
    {
        for (int i = 0; i < folhaMensal.size(); i++)
        {
            if (folhaMensal[i].getDataFolha().getMes() == mes && folhaMensal[i].getDataFolha().getAno() == ano) // Verifica se a folha enconrada � a correta
            {
                for (int l = 0; l < folhaMensal[i].retornaTamanhoVecDados(); l++) // Percorre todo o vector de dados que guarda as informa��es dos funcio�rios
                {
                    DadosFolha dado;
                    // Adiciona os funcion�rios dependendo se ainda est�o ativos na empresa, ou seja, n�o foram demitidos
                    if (mes == 1 || folhaMensal[i].retornaDadosFunc(l).getDataIngresso().getMes() == mes && folhaMensal[i].retornaDadosFunc(l).getDataIngresso().getAno() == ano)
                    {
                        dado.setSalarioBruto(folhaMensal[i].retornaDadosFunc(l).getSalarioBruto());
                        dado.setSalarioLiquido(folhaMensal[i].retornaDadosFunc(l).getSalarioLiquido());
                        dado.setCargaHoraria(folhaMensal[i].retornaDadosFunc(l).getCargaHoraria());
                        dado.setHorasExtras(folhaMensal[i].retornaDadosFunc(l).getHorasExtras());
                        dado.setDiasTrabalhados(folhaMensal[i].retornaDadosFunc(l).getDiasTrabalhados());
                        dado.setImpostoRenda(folhaMensal[i].retornaDadosFunc(l).getImpostoRenda());
                        dado.setInss(folhaMensal[i].retornaDadosFunc(l).getInss());
                        dado.setNome(folhaMensal[i].retornaDadosFunc(l).getNome());
                        dado.setCodigoFunc(folhaMensal[i].retornaDadosFunc(l).getCodigoFunc());
                        dado.setDataIngresso(folhaMensal[i].retornaDadosFunc(l).getDataIngresso());
                        dado.setDataDemissao(folhaMensal[i].retornaDadosFunc(l).getDataDemissao());
                        dado.setTipo(folhaMensal[i].retornaDadosFunc(l).getTipo());

                        dados.push_back(dado);
                    }
                    else
                    {
                        if (folhaMensal[i].retornaDadosFunc(l).getCodigoFunc() == dados[l].getCodigoFunc())
                        {
                            // Faz as somas de todos os meses que o funcion�rio trabalhou
                            somaSalarioBruto = dados[l].getSalarioBruto() + folhaMensal[i].retornaDadosFunc(l).getSalarioBruto();
                            somaSalarioLiquido = dados[l].getSalarioLiquido() + folhaMensal[i].retornaDadosFunc(l).getSalarioLiquido();
                            somaInss = dados[l].getInss() + folhaMensal[i].retornaDadosFunc(l).getInss();
                            somaImpostoRenda = dados[l].getImpostoRenda() + folhaMensal[i].retornaDadosFunc(l).getImpostoRenda();
                            somaCargaHoraria = dados[l].getCargaHoraria() + folhaMensal[i].retornaDadosFunc(l).getCargaHoraria();
                            somaHorasExtras = dados[l].getHorasExtras() + folhaMensal[i].retornaDadosFunc(l).getHorasExtras();
                            somaDiasTrabalhados = dados[l].getDiasTrabalhados() + folhaMensal[i].retornaDadosFunc(l).getDiasTrabalhados();

                            dados[l].setSalarioBruto(somaSalarioBruto);
                            dados[l].setSalarioLiquido(somaSalarioLiquido);
                            dados[l].setCargaHoraria(somaCargaHoraria);
                            dados[l].setHorasExtras(somaHorasExtras);
                            dados[l].setDiasTrabalhados(somaDiasTrabalhados);
                            dados[l].setImpostoRenda(somaImpostoRenda);
                            dados[l].setInss(somaInss);
                        }
                    }
                }

                break;
            }
        }
        if (mes == 12)
        {
            break;
        }
        mes++;
    }
    cout << "Folha Anual calculada com sucesso!" << endl;
    setDataFolha(0, ano);
}

void FolhaSalarial::exibeFolhaAnual() // Exibe a folha anual da empresa j� calculada previamente
{
    system("cls");
    cout << "FOLHA REFERENTE AO ANO DE " << dataFolha.getAno() << endl
         << endl;

    for (int i = 0; i < retornaTamanhoVecDados(); i++)
    {
        gastoAnual += dados[i].getSalarioBruto();
        cout << "Nome: " << dados[i].getNome() << "    ";

        cout << "-    C�digo do Funcion�rio: " << dados[i].getCodigoFunc() << endl;

        cout << "Sal�rio bruto: R$ " << dados[i].getSalarioBruto() << ", ";

        cout << "Descontos dos Impostos: R$ " << (dados[i].getImpostoRenda() + dados[i].getInss()) << ", ";

        cout << "S�lario l�quido: R$ " << dados[i].getSalarioLiquido() << endl;

        cout << "Cargo: ";

        if (dados[i].getTipo() == 1)
        {
            cout << "Operador" << endl;
        }
        if (dados[i].getTipo() == 2)
        {
            cout << "Gerente" << endl;
        }
        if (dados[i].getTipo() == 3)
        {
            cout << "Diretor" << endl;
        }
        if (dados[i].getTipo() == 4)
        {
            cout << "Presidente" << endl;
        }
        // se as condi��es abaixo forem atendidas quer dizer que o funcion�rio foi demitido, mostrando a mensagem de demiss�o
        if (dados[i].getDataDemissao().getAno() != 0 && dados[i].getDataDemissao().getMes() != 0 && dados[i].getDataDemissao().getDia() != 0)
        {
            if (dados[i].getDataDemissao().getAno() <= dataFolha.getAno())
            {
                if (dados[i].getDataDemissao().getMes() <= dataFolha.getMes())
                {
                    if (dados[i].getDataDemissao().getDia() <= dataFolha.getDia())
                    {
                        cout << "Funcion�rio demitido em ";
                        dados[i].getDataDemissao().toStringData();
                    }
                }
            }
        }

        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << "\nGasto anual da empresa: R$ " << gastoAnual << endl
         << endl;
}
