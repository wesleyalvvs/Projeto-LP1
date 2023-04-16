#pragma once
#include "Funcionario.h"
#include "Diretor.h"
#include "Operador.h"
#include "Presidente.h"
#include "Gerente.h"
#include <vector>
#include "FolhaSalarial.h"

class Gerenciador // Classe que gerencia todas as funcionalidades do programa
{
    public:
        Gerenciador();
        virtual ~Gerenciador();

        void addFuncioanario();                         // Adiciona um funcion�rio aos registros
        void editarRegistro();                          // Edita uma das informa��es do funcion�rio
        void excluirRegistro();                         // Deleta o registro de um funcion�rio, exceto o presidente ou diretor
        void demissaoFunc();                            // Demiss�o do funcion�rio - � adicionada uma data de demiss�o ao registro do funcion�rio 
        void exibirRegistro();                          // Exibe todas as informa��es de um funcion�rio
        void exibirLista();                             // Exibe todos os funcion�rios
        void exibirListaTipo();                         // Exibe a lista de funcionarios por tipo
        void concederAumento();                         // Concede aumento de acordo com os requisitos
        void buscarFuncionario();                       // Busca por nome, cidade, bairro e periodo de tempo ou c�digo
        void toStringFuncionario(int index);            // Retorna todos os dados do funcionario
        void folhaSalarial();                           // M�todo para manipula��o de todas as folhas salariais
        void salvarArquivo();                           // Salva em arquivo as informa��es da folha de pagamento
        void lerArquivo();                              // Ler os dados do arquivo e salva no programa
        void deletaArquivo();                           // Deleta as informa��es do arquivo
        int retornaArquivoVazio(const char* file_name); // Verifica se o arquivo em que s�o armazenadas informa��es est� ou n�o vazio
        void salvaArquivoFolha(int tipof);              // Salva os dados das folhas salariais em arquivo
        void lerArquivoFolha();                         // L� do arquivo os dados das folhas salariais

    private:
        std::vector <Funcionario *> registros;          // Vector de ponteiro para funcion�rio que armazena os registros de todos os funcion�rios
        std::vector <FolhaSalarial> folha;              // Vector para armazenar informa��es das folhas mensais
        std::vector <FolhaSalarial> folhaAnual;         // Vector para armazenar as folhas mensais dos anos pedidos pelo usu�rio
        std::vector <DadosFolha> dadosarquivo;          // Este vector armazena as informa��es dos arquivos das Folhas Salariais
};