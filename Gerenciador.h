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

        void addFuncioanario();                         // Adiciona um funcionário aos registros
        void editarRegistro();                          // Edita uma das informações do funcionário
        void excluirRegistro();                         // Deleta o registro de um funcionário, exceto o presidente ou diretor
        void demissaoFunc();                            // Demissão do funcionário - é adicionada uma data de demissão ao registro do funcionário 
        void exibirRegistro();                          // Exibe todas as informações de um funcionário
        void exibirLista();                             // Exibe todos os funcionários
        void exibirListaTipo();                         // Exibe a lista de funcionarios por tipo
        void concederAumento();                         // Concede aumento de acordo com os requisitos
        void buscarFuncionario();                       // Busca por nome, cidade, bairro e periodo de tempo ou código
        void toStringFuncionario(int index);            // Retorna todos os dados do funcionario
        void folhaSalarial();                           // Método para manipulação de todas as folhas salariais
        void salvarArquivo();                           // Salva em arquivo as informações da folha de pagamento
        void lerArquivo();                              // Ler os dados do arquivo e salva no programa
        void deletaArquivo();                           // Deleta as informações do arquivo
        int retornaArquivoVazio(const char* file_name); // Verifica se o arquivo em que são armazenadas informações está ou não vazio
        void salvaArquivoFolha(int tipof);              // Salva os dados das folhas salariais em arquivo
        void lerArquivoFolha();                         // Lê do arquivo os dados das folhas salariais

    private:
        std::vector <Funcionario *> registros;          // Vector de ponteiro para funcionário que armazena os registros de todos os funcionários
        std::vector <FolhaSalarial> folha;              // Vector para armazenar informações das folhas mensais
        std::vector <FolhaSalarial> folhaAnual;         // Vector para armazenar as folhas mensais dos anos pedidos pelo usuário
        std::vector <DadosFolha> dadosarquivo;          // Este vector armazena as informações dos arquivos das Folhas Salariais
};