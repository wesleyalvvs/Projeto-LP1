/*
============== DOCUMENTAÇÃO ==============
*   
*   AUTORES: Wesley Alves, Ludmila Gomes
*   DATA: desde 30/04/2022
*   
*   OBJETIVO: Criar um programa capaz de armazenar as informações de funcionários de uma empresa,
*             além de manipular estes. Ademais, o software também é capaz de armazenar os dados relativos
*             às folhas salariais dos empregados da empresa, tanto mensais, quanto anuais.
*   
*   DESCRIÇÃO: O programa gerencia os dados de uma empresa em relação aos seus funcionários e às folhas salariais.
*   
*   COMO OPERAR O PROGRAMA: A operação do sistema por parte do usuário ocorre através dos campos de digitação. Assim,
*                           surgem menus na tela, e o usuário deverá digitar a entrada adequada indicada pelo próprio
*                           programa.
*   
*   SITUAÇÕES DE ERRO (SE EXISTIREM): Passagem de dados com acentuação para arquivos.
*   
============== ============== ==============
*/

#include "Gerenciador.h"
#include <iostream>
#include <locale.h> // permite o uso de caracteres com acentuação

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); // Configura o terminal para a língua portuguesa

    char opcao;
    Gerenciador g;
    
   if(!g.retornaArquivoVazio("dados.txt") == 0) // verifica se o arquivo está vazio para depois ser carregado no programa
    {
       g.lerArquivo();
    }

    if(!g.retornaArquivoVazio("folha.txt") == 0) // verifica se o arquivo está vazio para depois ser caregado no programa
    {
       g.lerArquivoFolha();
    }

    while(1) // sempre vai repetir o menu abaixo pois são as funcionalidades que o programa pode executar
    {
        system("cls");
        cout << "Digite o número correspondente a opção que deseja executar no programa" << endl << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1  - Adicionar Funcionário(a)" << endl;
        cout << "2  - Editar o registro de um funcionário(a)" << endl;
        cout << "3  - Excluir Registro de Funcionário(a) / Demitir um funcionário" << endl;
        cout << "4  - Exibir Registro de Funcionário(a)" << endl;
        cout << "5  - Exibir Todos os Funcionários" << endl;
        cout << "6  - Exibir Lista de Funcionários de acordo com Tipo" << endl;
        cout << "7  - Conceder Aumento para todos os Funcionários" << endl;
        cout << "8  - Buscar um Funcionário(a)" << endl;
        cout << "9  - Acessar funcionalidades da Folha Salarial" << endl;
        cout << "0  - Sair do Programa" << endl;
        cout << "----------------------------------------------------" << endl << endl;
        cout << "Opção: ";
        cin >> opcao;
        system("cls");

        switch (opcao) // Executa a funcionalidade do programa que o usuário escolher
        {
        case '0':
        
            g.deletaArquivo(); // sempre deleta o arquivo antes de salvá-lo. Isso se faz necessário para sempre salvar os dados dos funcionários atualizados
            g.salvarArquivo();

            g.salvaArquivoFolha(1); // salva a folha mensal
            g.salvaArquivoFolha(2); // salva a folha anual
            cout << "Programa encerrado!\n";
            return 0;
            
        case '1':
            
            g.addFuncioanario();
            system("pause");
            break;
            
        case '2':

            g.editarRegistro();
            system("pause");
            break;
            
        case '3':

            char numero;
            cout << "Digite: 1 - para Excluir o registro de um funcionário ou / 2 - para demitir um funcionário" << endl;
            cout << "Opção: ";
            cin >> numero;
            
            if(numero == '1') // Excluir o registro
            {
                g.excluirRegistro();
            }
            else if(numero == '2') // Demitir um funcionário
            {
                g.demissaoFunc();
            }
            else
            {
                cout << "Opção inválida.\n";
            }
            system("pause");
            break;
            
        case '4':

            g.exibirRegistro();
            system("pause");
            break;
            
        case '5':

            g.exibirLista();
            system("pause");
            break;
            
        case '6':

            g.exibirListaTipo();
            system("pause");
            break;
            
        case '7':

            g.concederAumento();
            system("pause");
            break;
            
        case '8':

            g.buscarFuncionario();
            system("pause");
            break;
            
        case '9':
        
            g.folhaSalarial();
            system("pause");
            break;
            
        default:
        
            cout << "Opção inválida!\n";
            system("pause");
            break;
        }
    }
}

