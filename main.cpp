/*
============== DOCUMENTA��O ==============
*   
*   AUTORES: Wesley Alves, Ludmila Gomes
*   DATA: desde 30/04/2022
*   
*   OBJETIVO: Criar um programa capaz de armazenar as informa��es de funcion�rios de uma empresa,
*             al�m de manipular estes. Ademais, o software tamb�m � capaz de armazenar os dados relativos
*             �s folhas salariais dos empregados da empresa, tanto mensais, quanto anuais.
*   
*   DESCRI��O: O programa gerencia os dados de uma empresa em rela��o aos seus funcion�rios e �s folhas salariais.
*   
*   COMO OPERAR O PROGRAMA: A opera��o do sistema por parte do usu�rio ocorre atrav�s dos campos de digita��o. Assim,
*                           surgem menus na tela, e o usu�rio dever� digitar a entrada adequada indicada pelo pr�prio
*                           programa.
*   
*   SITUA��ES DE ERRO (SE EXISTIREM): Passagem de dados com acentua��o para arquivos.
*   
============== ============== ==============
*/

#include "Gerenciador.h"
#include <iostream>
#include <locale.h> // permite o uso de caracteres com acentua��o

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); // Configura o terminal para a l�ngua portuguesa

    char opcao;
    Gerenciador g;
    
   if(!g.retornaArquivoVazio("dados.txt") == 0) // verifica se o arquivo est� vazio para depois ser carregado no programa
    {
       g.lerArquivo();
    }

    if(!g.retornaArquivoVazio("folha.txt") == 0) // verifica se o arquivo est� vazio para depois ser caregado no programa
    {
       g.lerArquivoFolha();
    }

    while(1) // sempre vai repetir o menu abaixo pois s�o as funcionalidades que o programa pode executar
    {
        system("cls");
        cout << "Digite o n�mero correspondente a op��o que deseja executar no programa" << endl << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1  - Adicionar Funcion�rio(a)" << endl;
        cout << "2  - Editar o registro de um funcion�rio(a)" << endl;
        cout << "3  - Excluir Registro de Funcion�rio(a) / Demitir um funcion�rio" << endl;
        cout << "4  - Exibir Registro de Funcion�rio(a)" << endl;
        cout << "5  - Exibir Todos os Funcion�rios" << endl;
        cout << "6  - Exibir Lista de Funcion�rios de acordo com Tipo" << endl;
        cout << "7  - Conceder Aumento para todos os Funcion�rios" << endl;
        cout << "8  - Buscar um Funcion�rio(a)" << endl;
        cout << "9  - Acessar funcionalidades da Folha Salarial" << endl;
        cout << "0  - Sair do Programa" << endl;
        cout << "----------------------------------------------------" << endl << endl;
        cout << "Op��o: ";
        cin >> opcao;
        system("cls");

        switch (opcao) // Executa a funcionalidade do programa que o usu�rio escolher
        {
        case '0':
        
            g.deletaArquivo(); // sempre deleta o arquivo antes de salv�-lo. Isso se faz necess�rio para sempre salvar os dados dos funcion�rios atualizados
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
            cout << "Digite: 1 - para Excluir o registro de um funcion�rio ou / 2 - para demitir um funcion�rio" << endl;
            cout << "Op��o: ";
            cin >> numero;
            
            if(numero == '1') // Excluir o registro
            {
                g.excluirRegistro();
            }
            else if(numero == '2') // Demitir um funcion�rio
            {
                g.demissaoFunc();
            }
            else
            {
                cout << "Op��o inv�lida.\n";
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
        
            cout << "Op��o inv�lida!\n";
            system("pause");
            break;
        }
    }
}

