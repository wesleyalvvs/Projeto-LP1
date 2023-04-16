#include "Gerenciador.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "VerificaCaractere.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

// Construtor e Destrutor da classe Gerenciador
Gerenciador::Gerenciador()
{
}

Gerenciador::~Gerenciador() 
{
    int i;
    
    for (i = 0; i < registros.size(); i++)
    {
        delete registros[i];
    }
}

void Gerenciador::addFuncioanario() // Adiciona um funcion�rio no vector de registros
{
    // Vari�veis que ser�o utilizadas para salvar as informa��es dos funcion�rios
    Funcionario *func;                
    int tipo;                        
    int diaA, mesA, anoA;             // dia, m�s e ano referentes � data de admiss�o do funcion�rio
    int diaD = 0, mesD = 0, anoD = 0; // dia, m�s e ano referentes � data de demiss�o do funcion�rio
    double salario;
    string nome;
    string codigoF;
    string cpf;
    string rg;
    string rua, bairro, cidade, estado, cep, numero;
    string telefone;
    string areaSupervisao;
    string areaFormacao;
    string areaFormacaoMaxima;
    string url, comando;

    cout << "Insira os dados do funcion�rio:\n";

    int v; // Vari�vel para verifica��o dos dados

    fflush(stdin);

    while (1) // La�o de repeti��o para verificar o nome do funcion�rio recebido
    {
        v = 0;

        cout << "Nome: ";
        getline(cin, nome);

        if (nome.size() > 30) // Verifica se o nome � maior que 30 caracteres
        {
            cout << "Erro: Nome excede limite de 30 caracteres." << endl;
            v++;
        }

        if (!isLetter(nome)) // Verifica se o nome possui caracteres especiais
        {
            cout << "Erro: Nome possui caracteres especiais.\n";
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    cout << "C�digo do Funcion�rio: ";
    fflush(stdin);

    while (1) // La�o de repeti��o para verificar o c�digo do funcion�rio recebido
    {
        int cont = 0;
        getline(cin, codigoF);

        for (int i = 0; i < registros.size(); i++) // Verifica se o c�digo recebido � repetido
        {
            if (codigoF == registros[i]->getCodigoFuncionario())
            {
                cout << "C�digo do funcion�rio est� duplicado. Digite novamente.\n";
                cout << "C�digo do funcion�rio: ";
                break;
            }
            else
            {
                cont++;
            }
        }
        if (cont == registros.size())
        {
            cout << "C�digo aceito!" << endl;
            break;
        }
    }

    while (1) // La�o para verificar se o cpf foi digitado corretamente
    {
        v = 0;

        cout << "CPF: ";
        cin >> cpf;

        if (!isDigit(cpf)) // Verifica se o dado digitado � apenas n�meros
        {
            cout << "Erro: N�mero de CPF inv�lido - CPF digitado possui letras." << endl;
            v++;
        }
        if (cpf.size() > 11) // Verifica se o cpf possui mais de 11 d�gitos
        {
            cout << "Erro: N�mero do CPF inv�lido - CPF possui mais de 11 digitos." << endl;
            v++;
        }
        else if (cpf.size() < 11) // Verifica se o cpf possui menos de 11 d�gitos
        {
            cout << "Erro: N�mero do CPF inv�lido - CPF possui menos de 11 digitos." << endl;
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    while (1) // La�o de repeti��o para verificar o RG do funcion�rio recebido
    {
        v = 0;
        cout << "Digite o RG: ";
        cin >> rg;

        if (!isDigit(rg))
        {
            cout << "Erro: Numero de RG inv�lido - RG digitado possui letras." << endl;
            v++;
        }
        if (rg.size() > 20)
        {
            cout << "Erro: N�mero de RG inv�lido - RG possui mais de 20 d�gitos." << endl;
            v++;
        }
        if (v == 0)
        {
            break;
        }
    }

    int preferencia; // Pergunta ao usu�rio se ele deseja inserir todos os dados do endere�o ou prefere buscar pelo cep

    cout << "\nDigite: 0 - escrever todas as informa��es relativas ao Endere�o/ 1 - busca autom�tica pelo CEP: ";
    cin >> preferencia;

    if (preferencia == 0)
    {
        cout << "Digite o Endere�o:\n";
        while (1) // La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Rua: ";
            cin.ignore();
            getline(cin, rua);

            if (!isLetter(rua))
            {
                cout << "Erro: Nome de rua inv�lido.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        while (1) // La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "N�mero: ";
            cin >> numero;

            if (numero.size() > 4)
            {
                cout << "Erro: N�mero inv�lido - N�mero possui mais de 4 d�gitos.\n";
                v++;
            }
            if (!isDigit(numero))
            {
                cout << "Erro: N�mero inv�lido - N�mero digitado possui letras.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        while (1)// La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "CEP: ";
            cin >> cep;

            if (!isDigit(cep))
            {
                cout << "Erro: CEP inv�lido - CEP digitado com letras." << endl;
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        while (1)// La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Cidade: ";
            cin.ignore();
            getline(cin, cidade);

            if (!isLetter(cidade))
            {
                cout << "Erro: Nome de Cidade inv�lido - Nome de cidade digitado possui n�meros.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        while (1)// La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Bairro: ";
            getline(cin, bairro);

            if (!isLetter(bairro))
            {
                cout << "Erro: Nome de Bairro inv�lido - Nome digitado possui n�meros.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        while (1)// La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Estado: ";
            cin >> estado;

            if (!isLetter(estado))
            {
                cout << "Erro: Nome de Estado inv�lido - Nome digitado possui n�meros.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }
    }
    else if (preferencia == 1) // Faz a busca autom�tica de todos os dados do endere�o pelo cep informado
    {
        fstream fs;
        string linha, dado;
        int i = 0, posicao;

        while (1)// La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Digite seu CEP: ";
            cin >> cep;

            if (!isDigit(cep))
            {
                cout << "Erro: CEP inv�lido - CEP digitado com letras." << endl;
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }
        cout << endl;
        while (1) // La�o para Verificar se os dados do endere�o est�o sendo digitados corretamente
        {
            v = 0;

            cout << "Digite o n�mero da resid�ncia: ";
            cin >> numero;

            if (numero.size() > 4)
            {
                cout << "Erro: N�mero inv�lido - N�mero possui mais de 4 d�gitos.\n";
                v++;
            }
            if (!isDigit(numero))
            {
                cout << "Erro: N�mero inv�lido - N�mero digitado possui letras.\n";
                v++;
            }

            if (v == 0)
            {
                break;
            }
        }

        url = "https://viacep.com.br/ws/" + cep + "/json/";
        comando = "wget -qO cep.txt " + url;
        // wget -qO cep.txt https://viacep.com.br/ws/58035-480"/json/ meu cep

        system(comando.c_str());

        fs.open("cep.txt", fstream::in);
        if (!fs.is_open())
        {
            cout << "Arquivo n�o pode ser aberto.\n";
        }

        while (!fs.eof())
        {
            getline(fs, linha);

            if (i == 2) // logradouro
            {
                posicao = linha.find(':');
                rua = linha.substr(posicao + 3, linha.size() - 2 - posicao - 3); 
            }

            if (i == 4) // bairro
            {
                posicao = linha.find(':');
                bairro = linha.substr(posicao + 3, linha.size() - 2 - posicao - 3);
            }

            if (i == 5) // localidade
            {
                posicao = linha.find(':');
                cidade = linha.substr(posicao + 3, linha.size() - 2 - posicao - 3); 
            }

            if (i == 6) // uf
            {
                posicao = linha.find(':');
                estado = linha.substr(posicao + 3, linha.size() - 2 - posicao - 3);
            }
            i++;
        }
    }

    while (1) // Verifica se o n�mero do telefone est� digitado corretamente
    {
        v = 0;

        cout << "Telefone: ";
        cin >> telefone;

        if (!isDigit(telefone))
        {
            cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui letras." << endl;
            v++;
        }

        if (telefone.size() > 12)
        {
            cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui mais de 12 d�gitos." << endl;
            v++;
        }
        else if (telefone.size() < 11)
        {
            cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui menos de 11 d�gitos." << endl;
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    while (1) // Verifica se o s�lario esta sendo digitado corretamente
    {
        v = 0;

        cout << "Sal�rio: ";
        cin >> salario;

        if (salario < 0)
        {
            cout << "Erro: Sal�rio inv�lido - N�o existe sal�rio negativo." << endl;
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    cout << "Digite o N�mero (inteiro) da Data de ingresso:\n";

    while (1) // Verifica se os n�meros da data de ingresso est�o digitados corretamente
    {
        v = 0;

        cout << "Dia: ";
        cin >> diaA;
        cout << "M�s: ";
        cin >> mesA;
        cout << "Ano: ";
        cin >> anoA;

        if (diaA < 1)
        {
            cout << "Erro: Dia inv�lido - N�o existe dia negativo." << endl;
            v++;
        }

        if (mesA == 1 || mesA == 3 || mesA == 5 || mesA == 7 || mesA == 8 || mesA == 10 || mesA == 12) // && dia > 31)
        {
            if (diaA > 31)
            {
                cout << "Erro: Dia inv�lido - Esse m�s s� possui 31 dias." << endl;
                v++;
            }
        }

        if (mesA == 4 || mesA == 6 || mesA == 9 || mesA == 11) // && dia > 30)
        {
            if (diaA > 30)
            {
                cout << "Erro: Dia inv�lido - Esse m�s s� possui 30 dias." << endl;
                v++;
            }
        }

        if (mesA == 2)
        {
            if (diaA > 28)
            {
                cout << "Erro: Dia inv�lido - Fevereiro s� possui 28 dias." << endl;
                v++;
            }
        }

        if (mesA < 1)
        {
            cout << "Erro: M�s inv�lido - N�o existe m�s com n�mero negativo." << endl;
            v++;

            if (diaA > 31)
            {
                cout << "Erro: Dia inv�lido - N�o existe (em qualquer m�s) dia maior que 31." << endl;
            }
        }

        if (mesA > 12)
        {
            cout << "Erro: M�s inv�lido - Existem apenas 12 meses." << endl;

            if (diaA > 31)
            {
                cout << "Erro: Dia inv�lido - N�o existe (em qualquer m�s) dia maior que 31." << endl;
            }
        }

        if (anoA > 2022)
        {
            cout << "Erro: Ano inv�lido - Ano inexistente." << endl;
            v++;
        }

        if (anoA < 0)
        {
            cout << "Erro: Ano inv�lido - N�o existe ano negativo." << endl;
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    cout << "Escolha o tipo do funcion�rio de acordo com a tabela abaixo:\n\n";
    cout << " 1 - Operador\n";
    cout << " 2 - Gerente\n";
    cout << " 3 - Diretor\n";
    cout << " 4 - Presidente\n\n";
    cout << "Insira o tipo do funcion�rio: ";

    while (1)
    {
        v = 0;
        cin >> tipo;

        if (tipo < 0 || tipo > 4) // Verifica se o tipo foi digitado corretamente (deve estar entre as op��es 1 a 4)
        {
            cout << "Tipo digitado inv�lido." << endl;
            v++;
        }

        if (v == 0)
        {
            break;
        }
    }

    if (tipo == 1)
    {
        // Adiciona Operador
        func = new Operador(nome, Endereco(rua, numero, cep, cidade, bairro, estado), telefone, cpf, rg, codigoF, salario, Data(mesA, diaA, anoA), Data(mesD, diaD, anoD));
        registros.push_back(func);
    }

    if (tipo == 2)
    {
        // Adiciona Gerente - nome da �rea de supervis�o
        cout << "Insira a �rea de supervis�o deste gerente: ";
        cin.ignore();
        getline(cin, areaSupervisao);
        func = new Gerente(nome, Endereco(rua, numero, cep, cidade, bairro, estado), telefone, cpf, rg, codigoF, salario, Data(mesA, diaA, anoA), Data(mesD, diaD, anoD), areaSupervisao);
        registros.push_back(func);
    }

    if (tipo == 3)
    {
        // Adiciona Diretor - nome da �rea de supervis�o e �rea de forma��o
        cout << "Insira a �rea de supervis�o deste diretor: ";
        cin.ignore();
        getline(cin, areaSupervisao);
        cout << "\n";
        cout << "Insira a �rea de forma��o deste diretor: ";
        getline(cin, areaFormacao);

        func = new Diretor(nome, Endereco(rua, numero, cep, cidade, bairro, estado), telefone, cpf, rg, codigoF, salario, Data(mesA, diaA, anoA), Data(mesD, diaD, anoD), areaSupervisao, areaFormacao);
        registros.push_back(func);
    }

    if (tipo == 4)
    {
        // Adiciona Presidente - �rea de forma��o e qual forma��o acad�mica m�xima (por exemplo, especialista, mestre, doutor...)
        cout << "Insira a �rea de forma��o do presidente: ";
        cin.ignore();
        getline(cin, areaFormacao);

        cout << "Insira a forma��o acad�mica m�xima do presidente: ";
        getline(cin, areaFormacaoMaxima);

        func = new Presidente(nome, Endereco(rua, numero, cep, cidade, bairro, estado), telefone, cpf, rg, codigoF, salario, Data(mesA, diaA, anoA), Data(mesD, diaD, anoD), areaFormacao, areaFormacaoMaxima);
        registros.push_back(func);
    }
    cout << "\nFuncion�rio adicionado com sucesso!\n";
}

void Gerenciador::editarRegistro() // Edita as informa��es dos funcion�rios (as verifica��es de dados informadas pelo usu�rio s�o as mesmas do m�todo addFuncioanario())
{
    // Vari�veis utilizadas para editar alguma informa��o do registro do funcion�rio
    string cFuncionario;
    string nome;
    string codigoF;
    string cpf;
    string rg;
    string rua, bairro, cidade, estado, cep, numero;
    string telefone;
    string areaSupervisao;
    string areaFormacao;
    string areaFormacaoMaxima;
    float salario;
    int dia, mes, ano;
    int cont = 0;

    do
    {
        cout << "Digite o c�digo do funcion�rio: " << endl;
        cin >> cFuncionario;

        for (int i = 0; i < registros.size(); i++)
        {
            if (cFuncionario == registros[i]->getCodigoFuncionario())
            {
                cont = 1;
                int numeroDado, v;
                cout << "\nInforma��es sobre o funcion�rio:\n";

                cout << "1 - Nome: " << registros[i]->getNome() << endl;
                cout << "2 - C�digo do funcion�rio: " << registros[i]->getCodigoFuncionario() << endl;
                cout << "3 - CPF: " << registros[i]->getcpf() << endl;
                cout << "4 - RG: " << registros[i]->getRg() << endl;
                cout << "5 - Endere�o: ";
                registros[i]->getEndereco().toStringEnd();
                cout << "6 - Telefone: " << registros[i]->getTelefone() << endl;
                cout << "7 - Sal�rio: R$ " << registros[i]->getSalario() << endl;
                cout << "8 - Data de ingresso: ";
                registros[i]->getDataIngresso().toStringData();
                cout << "\n";

                if (registros[i]->getTipo() == 2)
                {
                    cout << "9 - �rea de supervis�o (gerente): " << ((Gerente *)registros[i])->getAreaS() << endl;
                }
                if (registros[i]->getTipo() == 3)
                {
                    cout << "10 - �rea de supervis�o (diretor): " << ((Diretor *)registros[i])->getAreaS() << endl;
                    cout << "11 - �rea de forma��o (diretor): " << ((Diretor *)registros[i])->getAreaF() << endl;
                }
                if (registros[i]->getTipo() == 4)
                {
                    cout << "12 - �rea de forma��o (presidente): " << ((Presidente *)registros[i])->getAreaFormacao() << endl;
                    cout << "13 - �rea acad�mica m�xima (presidente): " << ((Presidente *)registros[i])->getFormacaoAcademica() << endl;
                }
                do
                {
                    cout << "\nDigite o N�mero correspondente ao dado que deseja modificar: " << endl;
                    cin >> numeroDado;

                    switch (numeroDado)
                    {
                    case 1: // Modificar nome

                        fflush(stdin);

                        while (1) // la�o de repeti��o para verificar o nome do funcion�rio recebido
                        {
                            v = 0;

                            cout << "Digite o novo nome: ";
                            getline(cin, nome);

                            if (nome.size() > 30)
                            {
                                cout << "Erro: Nome excede limite de 30 caracteres" << endl;
                                v++;
                            }

                            if (!isLetter(nome))
                            {
                                cout << "Erro: Nome possui caracteres especiais.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        registros[i]->setNome(nome);
                        break;

                    case 2: // Modificar c�digo do funcion�rio

                        while (1) // la�o de repeti��o para verificar o nome do funcion�rio recebido
                        {
                            int cont = 0;
                            cout << "Digite o novo C�digo do Funcion�rio: ";
                            cin >> codigoF;

                            for (int i = 0; i < registros.size(); i++)
                            {
                                if (codigoF == registros[i]->getCodigoFuncionario())
                                {
                                    cout << "C�digo do funcion�rio est� duplicado.\n";
                                    cout << "Digite novamente.\n";
                                    cout << "C�digo do funcion�rio: ";
                                    break;
                                }
                                else
                                {
                                    cont++;
                                }
                            }
                            if (cont == registros.size())
                            {
                                cout << "C�digo editado com sucesso!" << endl;
                                break;
                            }
                        }

                        registros[i]->setCodigoFuncionario(codigoF);
                        break;

                    case 3: // Modificar cpf

                        while (1) // la�o de repeti��o para verificar o CPF do funcion�rio recebido
                        {
                            v = 0;

                            cout << "Digite o novo CPF: ";
                            cin >> cpf;

                            if (!isDigit(cpf))
                            {
                                cout << "Erro: N�mero de CPF inv�lido - CPF digitado possui letras." << endl;
                                v++;
                            }
                            if (cpf.size() > 11)
                            {
                                cout << "Erro: N�mero de CPF inv�lido - CPF possui mais de 11 d�gitos." << endl;
                                v++;
                            }
                            else if (cpf.size() < 11)
                            {
                                cout << "Erro: N�mero de CPF inv�lido - CPF possui menos de 11 digitos." << endl;
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }
                        
                        registros[i]->setCpf(cpf);
                        break;

                    case 4: // Modificar rg

                        while (1) // la�o de repeti��o para verificar o RG do funcion�rio recebido
                        {
                            v = 0;

                            cout << "Digite o novo RG: ";
                            cin >> rg;

                            if (!isDigit(rg))
                            {
                                cout << "Erro: N�mero de RG inv�lido - RG digitado possui letras." << endl;
                                v++;
                            }
                            if (rg.size() > 20)
                            {
                                cout << "Erro: N�mero de RG inv�lido - RG possui mais de 20 d�gitos." << endl;
                                v++;
                            }
                            if (v == 0)
                            {
                                break;
                            }
                        }

                        registros[i]->setRg(rg);
                        break;

                    case 5: // Modificar Endere�o

                        cout << "Digite o novo Endere�o:\n";
                        while (1)
                        {
                            v = 0;

                            cout << "Rua: ";
                            cin.ignore();
                            getline(cin, rua);

                            if (!isLetter(rua))
                            {
                                cout << "Erro: Nome de Rua inv�lido.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            v = 0;

                            cout << "N�mero: ";
                            cin >> numero;

                            if (numero.size() > 4)
                            {
                                cout << "Erro: N�mero inv�lido - N�mero possui mais de 4 d�gitos.\n";
                                v++;
                            }
                            if (!isDigit(numero))
                            {
                                cout << "Erro: N�mero inv�lido - N�mero digitado possui letras.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            v = 0;

                            cout << "CEP: ";
                            cin >> cep;

                            if (!isDigit(cep))
                            {
                                cout << "Erro: CEP inv�lido - CEP digitado com letras." << endl;
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            v = 0;

                            cout << "Cidade: ";
                            cin.ignore();
                            getline(cin, cidade);

                            if (!isLetter(cidade))
                            {
                                cout << "Erro: Nome de Cidade inv�lido - Nome de cidade digitado possui n�meros.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            v = 0;

                            cout << "Bairro: ";
                            getline(cin, bairro);

                            if (!isLetter(bairro))
                            {
                                cout << "Erro: Nome de Bairro inv�lido - Nome digitado possui n�meros.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            v = 0;

                            cout << "Estado: ";
                            cin >> estado;

                            if (!isLetter(estado))
                            {
                                cout << "Erro: Nome de Estado inv�lido - Nome digitado possui n�meros.\n";
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        registros[i]->setEndereco(Endereco(rua, numero, cep, cidade, bairro, estado));
                        break;

                    case 6: // Modificar telefone

                        while (1)
                        {
                            v = 0;

                            cout << "Digite o novo telefone: ";
                            cin >> telefone;

                            if (!isDigit(telefone))
                            {
                                cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui letras." << endl;
                                v++;
                            }

                            if (telefone.size() > 12)
                            {
                                cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui mais de 12 d�gitos." << endl;
                                v++;
                            }
                            else if (telefone.size() < 11)
                            {
                                cout << "Erro: N�mero de telefone inv�lido - N�mero de telefone digitado possui menos de 11 d�gitos." << endl;
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }
                        
                        registros[i]->setTelefone(telefone);
                        break;

                    case 7: // Modificar Sal�rio
                        cout << "Digite o novo Sal�rio: ";
                        while (1)
                        {
                            v = 0;

                            cout << "Sal�rio: R$ ";
                            cin >> salario;

                            if (salario < 0)
                            {
                                cout << "Erro: Sal�rio negativo � inv�lido - N�o existe sal�rio negativo." << endl;
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }
                        
                        registros[i]->setSalario(salario);
                        break;

                    case 8: // Modificar data de ingresso

                        cout << "Digite a nova Data de ingresso:\n";

                        while (1)
                        {
                            v = 0;

                            cout << "M�s: ";
                            cin >> mes;

                            if (mes < 1)
                            {
                                cout << "Erro: M�s inv�lido - N�o existe m�s com n�mero negativo." << endl;
                                v++;
                            }

                            if (mes > 12)
                            {
                                cout << "Erro: M�s inv�lido - Existem apenas 12 meses." << endl;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }
                        cout << "\n";

                        while (1) // Modifica a data de ingresso do funcion�rio
                        {
                            v = 0;

                            cout << "Dia: ";
                            cin >> dia;

                            if (dia < 1)
                            {
                                cout << "Erro: Dia inv�lido - N�o existe dia negativo/igual a 0." << endl;
                                v++;
                            }

                            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                            {
                                if (dia > 31)
                                {
                                    cout << "Erro: Dia inv�lido - Esse m�s s� possui 31 dias." << endl;
                                    v++;
                                }
                            }

                            if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                            {
                                if (dia > 30)
                                {
                                    cout << "Erro: Dia inv�lido. - Esse m�s s� possui 30 dias." << endl;
                                    v++;
                                }
                            }

                            if (mes == 2)
                            {
                                if (dia > 28)
                                {
                                    cout << "Erro: Dia inv�lido - Fevereiro s� possui 28 dias." << endl;
                                    v++;
                                }
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }

                        while (1)// Modifica a data de ingresso
                        {
                            v = 0;

                            cout << "Ano: ";
                            cin >> ano;

                            if (ano > 2022)
                            {
                                cout << "Erro: Ano inv�lido - Ano inexistente." << endl;
                                v++;
                            }

                            if (ano < 1)
                            {
                                cout << "Erro: Ano inv�lido - N�o existe ano negativo ou igual a 0." << endl;
                                v++;
                            }

                            if (v == 0)
                            {
                                break;
                            }
                        }
                        registros[i]->setDataIngresso(Data(mes, dia, ano));
                        break;

                    case 9: // Modificar �rea de supervis�o (gerente)
                        cout << "Digite a nova �rea de supervis�o (gerente): ";
                        cin >> areaSupervisao;

                        ((Gerente *)registros[i])->setAreaS(areaSupervisao);
                        break;

                    case 10: // Modificar �rea de supervis�o (diretor)
                        cout << "Digite a nova �rea de supervis�o (diretor): ";
                        cin >> areaSupervisao;
                        
                        ((Diretor *)registros[i])->setAreaS(areaSupervisao);
                        break;

                    case 11: // Modificar �rea de forma��o (diretor)
                        cout << "Digite a nova �rea de forma��o (diretor): ";
                        cin >> areaFormacao;
                        
                        ((Diretor *)registros[i])->setAreaF(areaFormacao);
                        break;

                    case 12: // Modificar �rea de forma��oo (presidente)
                        cout << "Digite a nova �rea de forma��oo (presidente): ";
                        cin >> areaFormacao;
                        
                        ((Presidente *)registros[i])->setAreaFormacao(areaFormacao);
                        break;

                    case 13: // Modificar forma��o acad�mica m�xima (presidente)
                        cout << "Digite a nova forma��o acad�mica m�xima (presidente): ";
                        cin >> areaFormacaoMaxima;
                        
                        ((Presidente *)registros[i])->setFormacaoAcademica(areaFormacaoMaxima);
                        break;

                    default:
                        cout << "Op��o inv�lida." << endl;
                        break;
                    }
                } while (numeroDado < 1 || numeroDado > 13);

                cout << "Dados do funcion�rio atualizados com sucesso!\n";
                toStringFuncionario(i);
                break;
            }
        }
        if (cont == 0)
        {
            cout << "Registro inv�lido." << endl;
        }

    } while (cont == 0);
}

void Gerenciador::demissaoFunc() // M�todo que demite um funcion�rio
{
    string cFuncionario;
    int cont = 0, contdem = 0;
    do
    {
        cout << "Digite o c�digo do funcion�rio: " << endl;
        cin >> cFuncionario;

        for (int i = 0; i < registros.size(); i++) // La�o para buscar o funcion�rio a ser demitido
        {
            if (registros[i]->getCodigoFuncionario().compare(cFuncionario) == 0)
            {
                cont++;
                char numeroConfirma;
                cout << "Tem certeza que deseja demitir " << registros[i]->getNome() << "?\n";
                cout << "   >>> Digite '1' para confirmar ou '0' para cancelar o procedimento: ";

                cin >> numeroConfirma;
                if (numeroConfirma == '1')
                {
                    while (1) // � adicionada aos dados do funcion�rio a data em que este foi demitido
                    {
                        contdem = 0;
                        cout << "Digite a data de demiss�o: " << endl;
                        int dia, mes, ano;
                        cout << "Dia: ";
                        cin >> dia;
                        cout << "M�s: ";
                        cin >> mes;
                        cout << "Ano: ";
                        cin >> ano;

                        if (ano < registros[i]->getDataIngresso().getAno())
                        {
                            contdem++;
                            cout << "Data digitada � de antes do funcion�rio ser admitido." << endl;
                        }
                        else if (ano == registros[i]->getDataIngresso().getAno() && mes < registros[i]->getDataIngresso().getMes())
                        {
                            contdem++;
                            cout << "Data digitada � de antes do funcion�rio ser admitido." << endl;
                        }
                        else if (ano == registros[i]->getDataIngresso().getAno() && mes == registros[i]->getDataIngresso().getMes() && dia < registros[i]->getDataIngresso().getDia())
                        {
                            contdem++;
                            cout << "Data digitada � de antes do funcion�rio ser admitido." << endl;
                        }
                        else
                        {
                            cout << "Funcion�rio demitido com sucesso!\n";
                            registros[i]->setDataDemissao(Data(mes, dia, ano));
                            break;
                        }
                    }
                }
                else if (numeroConfirma == '0') // Confirma��o se quer realmente demitir o funcion�rio
                {
                    cout << "Opera��o cancelada.\n";
                    break;
                }
                else
                {
                    cout << "Op��o inv�lida!\n";
                }

                if (cont == 1)
                {
                    break;
                }
            }
        }

        if (cont == 0)
        {
            cout << "C�digo do funcion�rio inv�lido!\n";
        }

    } while (cont == 0);
}

void Gerenciador::excluirRegistro() // Um funcion�rio � exclu�do dos registros 
{
    string cFuncionario;
    int cont = 0;

    cout << "Digite o c�digo do funcion�rio: " << endl;
    cin >> cFuncionario;

    for (int i = 0; i < registros.size(); i++)
    {
        cont++;
        if (registros[i]->getCodigoFuncionario().compare(cFuncionario) == 0)
        {
            if (registros[i]->getTipo() == 4)
            {
                cout << "Erro: Voc� n�o pode excluir o registro do Presidente!\n";
            }

            if (registros[i]->getTipo() == 3)
            {
                cout << "Erro: Voc� n�o pode excluir o registro do Diretor!\n";
            }

            char letraConfirma;
            cout << "Tem certeza que deseja excluir o registro de " << registros[i]->getNome() << "?\n";
            cout << "   >>> Digite '1' para confirmar ou '0' para cancelar o procedimento: ";

            cin >> letraConfirma;

            if (letraConfirma == '1')
            {
                cout << "\nFuncion�rio exclu�do com sucesso!\n";
                registros.erase(registros.begin() + i);
                break;
            }
            else if (letraConfirma == '0')
            {
                cout << "Opera��o cancelada.\n";
            }
            else if (letraConfirma != '0' || letraConfirma != '1')
            {
                cout << "Op��o inv�lida!\n";
            }
        }
        else if (cont == registros.size())
        {
            cout << "C�digo do funcion�rio inv�lido!\n";
        }
    }
}

void Gerenciador::exibirRegistro() // Exibe os dados de um funcion�rio
{
    string cFuncionario;
    int verifica = 0;
    cout << "Digite o c�digo do funcion�rio: " << endl;
    cin >> cFuncionario;

    for (int i = 0; i < registros.size(); i++)
    {
        if (registros[i]->getCodigoFuncionario().compare(cFuncionario) == 0)
        {
            toStringFuncionario(i);
            cout << "\n";
            verifica = 1;
            break;
        }
    }

    if(verifica == 0)
    {
        cout << "C�digo do funcion�rio inv�lido!\n";
    }
}

void Gerenciador::exibirLista() // Exibe a lista com todos os funcion�rios presentes nos registros
{
    cout << "\nLista de todos os funcion�rios da empresa:\n\n";
    for (int i = 0; i < registros.size(); i++)
    {
        toStringFuncionario(i);
        cout << "\n";
    }
}

void Gerenciador::exibirListaTipo() // Exibe a lista com funcion�rios de acordo com o Tipo do funcion�rio
{
    int tipo;

    cout << "Escolha o tipo de funcionario a ser exibido: " << endl;
    cout << "1 - Operador" << endl;
    cout << "2 - Gerente" << endl;
    cout << "3 - Diretor" << endl;
    cout << "4 - Presidente" << endl;

    cin >> tipo;

    switch (tipo)
    {
    case 1: // Exibe a lista de operadores
    {
        cout << "Lista - Operadores\n\n";
        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getTipo() == 1)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    case 2: // Exibe a lista dos gerentes
    {
        cout << "Lista - Gerente\n\n";
        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getTipo() == 2)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    case 3: // Exibe a lista dos diretores
    {
        cout << "Lista - Diretor\n\n";
        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getTipo() == 3)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    case 4: // Exibe a lista de presidentes
    {
        cout << "Presidente\n\n";
        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getTipo() == 4)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    default:

        cout << "Tipo digitado inv�lido.\n";
        break;
    }
}

void Gerenciador::concederAumento() // M�todo que concede aumento aos funcion�rios de acordo com os requisitos do projeto
{
    float aumento;
    for (int i = 0; i < registros.size(); i++)
    {
        // Porcentagem de aumento de sal�rio � referente ao tipo do funcion�rio
        if (registros[i]->getTipo() == 1) 
        {
            aumento = registros[i]->getSalario() * 0.05;
            registros[i]->setSalario(registros[i]->getSalario() + aumento);
        }

        if (registros[i]->getTipo() == 2)
        {
            aumento = registros[i]->getSalario() * 0.1;
            registros[i]->setSalario(registros[i]->getSalario() + aumento);
        }

        if (registros[i]->getTipo() == 3)
        {
            aumento = registros[i]->getSalario() * 0.2;
            registros[i]->setSalario(registros[i]->getSalario() + aumento);
        }

        if (registros[i]->getTipo() == 4)
        {
            aumento = registros[i]->getSalario() * 0.3;
            registros[i]->setSalario(registros[i]->getSalario() + aumento);
        }
    }
    cout << "Aumento concedido!" << endl;
}

void Gerenciador::buscarFuncionario() // Busca um funcion�rio dentre os cadastrados
{
    int tipoDado;
    string busca;

    cout << "Escolha o dado do funcion�rio de acordo com a tabela abaixo: " << endl;
    cout << "1 - Nome" << endl;
    cout << "2 - M�s/Ano" << endl;
    cout << "3 - Endere�o (bairro/cidade)" << endl;
    cout << "4 - C�digo do funcion�rio" << endl;

    cin >> tipoDado;
    cin.ignore();

    switch (tipoDado)
    {
    case 1: // Busca pelo nome
    {
        string busca;
        cout << "Digite o nome do funcion�rio: " << endl;
        getline(cin, busca);

        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getNome().find(busca) != string::npos)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }

    case 2: // Busca pelo intervalo de tempo
    {
        int mes1, mes2, ano1, ano2, opcao;

        cout << "Digite o intervalo de tempo de ingresso dos funcion�rios que deseja buscar:  " << endl;
        cout << "Do M�s: ";
        cin >> mes1;
        cout << "\n";
        cout << "Do Ano: ";
        cin >> ano1;
        cout << "\n";
        cout << "At� o M�s: ";
        cin >> mes2;
        cout << "\n";
        cout << "At� o Ano: ";
        cin >> ano2;
        cout << "\n";

        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getDataIngresso().getMes() >= mes1 && registros[i]->getDataIngresso().getMes() <= mes2 && registros[i]->getDataIngresso().getAno() >= ano1 && registros[i]->getDataIngresso().getAno() <= ano2)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }

        break;
    }

    case 3: // Busca pelo Endere�o do funcion�rio
    {
        string busca;
        cout << "Digite o Endere�o (bairro ou cidade) do funcion�rio: " << endl;
        getline(cin, busca);

        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getEndereco().getCidade().find(busca) != string::npos || registros[i]->getEndereco().getBairro().find(busca) != string::npos)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    case 4: // Busca pelo C�digo do funcion�rio
    {
        string busca;
        cout << "Digite o c�digo do funcion�rio: " << endl;
        getline(cin, busca);

        for (int i = 0; i < registros.size(); i++)
        {
            if (registros[i]->getCodigoFuncionario().compare(busca) == 0)
            {
                toStringFuncionario(i);
            }
            cout << "\n";
        }
        break;
    }
    default:
        cout << "Tipo digitado inv�lido\n";
        break;
    }
}

void Gerenciador::toStringFuncionario(int index) // M�todo ToString para imprimir as informa��es de um funcion�rio
{
    cout << "Nome: " << registros[index]->getNome() << "    ";
    cout << "-    C�digo do Funcion�rio: " << registros[index]->getCodigoFuncionario() << endl;
    cout << "Data de ingresso: ";
    registros[index]->getDataIngresso().toStringData();
    cout << "\n";
    cout << "CPF: " << registros[index]->getcpf() << "    -    ";
    cout << "RG: " << registros[index]->getRg() << endl;
    cout << "Endere�o: ";
    registros[index]->getEndereco().toStringEnd();
    cout << "Telefone: " << registros[index]->getTelefone() << endl;
    cout << "Sal�rio: R$ " << registros[index]->getSalario() << endl;

    if (registros[index]->getTipo() == 2)
    {
        cout << "�rea de Supervis�o: " << ((Gerente *)registros[index])->getAreaS();
        cout << "\n";
    }

    if (registros[index]->getTipo() == 3)
    {
        cout << "�rea de Supervis�o: " << ((Diretor *)registros[index])->getAreaS();
        cout << "\n";
        cout << "�rea de Forma��o: " << ((Diretor *)registros[index])->getAreaF();
        cout << "\n";
    }

    if (registros[index]->getTipo() == 4)
    {
        cout << "�rea de Forma��o: " << ((Presidente *)registros[index])->getAreaFormacao();
        cout << "\n";
        cout << "Forma��o Acad�mica M�xima: " << ((Presidente *)registros[index])->getFormacaoAcademica();
        cout << "\n";
    }
    if (registros[index]->getDataDemissao().getDia() > 0)
    {
        cout << "Funcion�rio demitido!" << endl;
    }
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Gerenciador::folhaSalarial() // opcaoMenu indica a escolha do usu�rio: se ele quer caluclar a folha ou imprimir folha do Funcion�rio ou folha da empresa
{
    int mes, ano, opcaoMenu;
    FolhaSalarial fSalarial; // objeto de FolhaSalarial usado para calcular as folhas salariais novas e adicionar no vector folha
    int cont = 0, verifica = 0, aux = 0;

    cout << "Escolha a opera��o relativa � Folha Salarial que deseja executar:" << endl;
    cout << "1 - Calcular Folha Salarial de um m�s" << endl;
    cout << "2 - Exibir a Folha Salarial de um m�s" << endl;
    cout << "3 - Exibir a Folha Salarial de um funcion�rio" << endl;
    cout << "4 - Calcular Folha Salarial de um ano" << endl;
    cout << "5 - Exibir Folha Salarial de um ano" << endl;

    cout << "Digite a op��o: ";
    cin >> opcaoMenu;

    if (opcaoMenu >= 1 && opcaoMenu <= 3)
    {
        cout << "Digite o m�s e ano:\n";
        cout << "M�s: ";
        cin >> mes;
        cout << "Ano: ";
        cin >> ano;
    }
    else if (opcaoMenu == 4 || opcaoMenu == 5)
    {
        cout << "Digite o Ano: ";
        cin >> ano;
    }

    switch (opcaoMenu)
    {
    case 1: // calcular a folha salarial mensal solicitando o m�s e o ano ao usu�rio
    {
        if (folha.size() == 0)//Verifica se existe dados no vetor de folha de pagamento
        {
            for (int i = 0; i < dadosarquivo.size(); i++)
            {
                if (!dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                {
                    fSalarial.retornaFuncAtivos(registros, mes, ano);
                    fSalarial.calcularFolhaMensal();
                    folha.push_back(fSalarial);
                    cout << "A Folha para o m�s foi calculada com sucesso.\n";
                    cont = 1;
                }
            }
        }

        if (cont == 0) // se n�o houver, o programa vai verificar tamb�m o vector de dados
        {
            for (int i = 0; i < folha.size(); i++)
            {
                cont == 0;

                if (folha[i].getDataFolha().getMes() == mes && folha[i].getDataFolha().getAno() == ano)
                {
                    aux = 1;
                    cout << "A Folha para o m�s j� foi calculada." << endl;
                    break;
                }
            }
            if (aux == 0)
            {
                for (int i = 0; i < dadosarquivo.size(); i++)
                {

                    if (dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                    {
                        aux = 1;
                        cout << "A Folha para o m�s j� foi calculada." << endl;
                        break;
                    }
                }
            }
        }

        if (aux == 0) // Se n�o encontrar a folha que o usu�rio digitou ent�o ser� feito o calculo
        {
            fSalarial.retornaFuncAtivos(registros, mes, ano);
            fSalarial.calcularFolhaMensal();
            folha.push_back(fSalarial);
            // folhaAnual.push_back(fSalarial);
            cout << "A Folha para o m�s foi calculada com sucesso.\n";
        }

        break;
    }
    case 2: // exibe a folha salarial mensal de acordo com o m�s e ano que o usu�rio digitar
    {
        aux = 0;
        if (folha.size() == 0)
        {
            for (int i = 0; i < dadosarquivo.size(); i++)
            {

                if (dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                {
                    aux = 1;
                    break;
                }
            }
            if (aux == 0)
            {
                cout << "N�o existem Folhas calculadas at� o momento.\n";
            }
        }
        if (aux == 1)// se os vector n�o estiverem vazios o programa vai procurar a folha e se achar vai imprimir na tela
        {
            for (int i = 0; i < dadosarquivo.size(); i++)
            {
                if (dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                {
                    cout << "Nome: " << dadosarquivo[i].getNome() << "    ";

                    cout << "-    C�digo do Funcion�rio: " << dadosarquivo[i].getCodigoFunc() << endl;

                    cout << "Sal�rio bruto: R$ " << dadosarquivo[i].getSalarioBruto() << ", ";

                    cout << "Descontos dos Impostos: R$ " << (dadosarquivo[i].getImpostoRenda() + dadosarquivo[i].getInss()) << ", ";

                    cout << "S�lario l�quido: R$ " << dadosarquivo[i].getSalarioLiquido() << endl;

                    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                }
            }
        }
        if (folha.size() != 0)
        {
            for (int i = 0; i < folha.size(); i++)
            {
                verifica = 0;
                if (folha[i].getDataFolha().getMes() == mes and folha[i].getDataFolha().getAno() == ano)
                {
                    verifica = 1;
                    folha[i].exibeFolhaMensal();
                    break;
                }
            }
            if (verifica == 0)
            {
                cout << "A Folha para o m�s ainda n�o foi calculada.\n";
            }
        }

        break;
    }
       
    case 3: // exibe a folha salarial mensal de um funcion�rio solicianto o m�s, o ano e o c�digo do funcion�rio
    {
        int cont2;
        string opcao;
        int n;
        cout << "Digite: 1 - Busca pelo nome completo / 2 - Busca pelo C�digo do Funcion�rio: ";
        cin >> n;
        cin.ignore();

        if (n == 1)
        {
            cout << "Digite o nome do Funcion�rio: ";
        }
        else if (n == 2)
        {
            cout << "Digite o C�digo do Funcion�rio: ";
        }

        getline(cin, opcao);

        cont = 0;  // folha.size()
        cont2 = 0; // dadosArquivo.size()
        aux = 0;   // vari�vel auxiliar

        if (folha.size() == 0)
        {
            cont++;
            // cout << "\n";
        }
        // cont = 0;
        if (dadosarquivo.size() == 0)
        {
            cont2++;
        }

        if (cont == 1 && cont2 == 1) // folha est� vazio E dadosArquivo tamb�m est� vazio
        {
            cout << "N�o existem folhas calculadas at� o momento.\n";
        }
        if (cont == 0) //  vai procurar a folha dentro do vector de folha
        {
            for (int i = 0; i < folha.size(); i++)
            {
                if (folha[i].getDataFolha().getMes() == mes and folha[i].getDataFolha().getAno() == ano)
                {
                    if (n == 1)
                    {
                        for (int j = 0; j < folha[i].retornaTamanhoVecDados(); j++)
                        {
                            if (folha[i].retornaDadosFunc(j).getNome().compare(opcao) == 0)
                            {
                                aux = 1;

                                cout << "Nome: " << folha[i].retornaDadosFunc(j).getNome() << "    ";

                                cout << "-    C�digo do Funcion�rio: " << folha[i].retornaDadosFunc(j).getCodigoFunc() << endl;

                                cout << "Sal�rio bruto: R$ " << folha[i].retornaDadosFunc(j).getSalarioBruto() << ", ";

                                cout << "Descontos dos Impostos: R$ " << (folha[i].retornaDadosFunc(j).getImpostoRenda() + folha[i].retornaDadosFunc(j).getInss()) << ", ";

                                cout << "S�lario l�quido: R$ " << folha[i].retornaDadosFunc(j).getSalarioLiquido() << endl;

                                cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                                break;
                            }
                        }
                    }
                    else if (n == 2)
                    {
                        for (int j = 0; j < folha[i].retornaTamanhoVecDados(); j++)
                        {
                            if (folha[i].retornaDadosFunc(j).getCodigoFunc().compare(opcao) == 0)
                            {
                                aux = 1;
                                folha[i].exibeFolhaFunc();
                                // cout << "\n";
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (cont2 == 0 && aux == 0) // vai procurar dentro do vector de dados
        {
            for (int i = 0; i < dadosarquivo.size(); i++)
            {
                if (dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                {
                    if (n == 1)
                    {
                        if (dadosarquivo[i].getNome().compare(opcao) == 0)
                        {
                            cout << "Nome: " << dadosarquivo[i].getNome() << "    ";

                            cout << "-    C�digo do Funcion�rio: " << dadosarquivo[i].getCodigoFunc() << endl;

                            cout << "Sal�rio bruto: R$ " << dadosarquivo[i].getSalarioBruto() << ", ";

                            cout << "Descontos dos Impostos: R$ " << (dadosarquivo[i].getImpostoRenda() + dadosarquivo[i].getInss()) << ", ";

                            cout << "S�lario l�quido: R$ " << dadosarquivo[i].getSalarioLiquido() << endl;

                            cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                    }
                    if (n == 2)
                    {
                        if (dadosarquivo[i].getCodigoFunc().compare(opcao) == 0)
                        {
                            cout << "Nome: " << dadosarquivo[i].getNome() << "    ";

                            cout << "-    C�digo do Funcion�rio: " << dadosarquivo[i].getCodigoFunc() << endl;

                            cout << "Sal�rio bruto: R$ " << dadosarquivo[i].getSalarioBruto() << ", ";

                            cout << "Descontos dos Impostos: R$ " << (dadosarquivo[i].getImpostoRenda() + dadosarquivo[i].getInss()) << ", ";

                            cout << "S�lario l�quido: R$ " << dadosarquivo[i].getSalarioLiquido() << endl;

                            cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                    }
                }
            }
        }
        break;
    }
    case 4: // Calcular Folha Salarial de um ano
    {
        mes = 1;
        verifica = 0;

        while (1)//Calcula uma folha de cada vez e adiciona no vetor de folhas, como a folha anual � calculada 
                 //baseada nas folhas de cada m�s do ano se a folha n�o foi calculada antes o programa calcula uma nova referente ao m�s aleatoriamente
        {
            FolhaSalarial f;
            verifica = 0;

            if (dadosarquivo.size() > 0)
            {
                for (int i = 0; i <= dadosarquivo.size(); i++)
                {
                    if (dadosarquivo[i].getDataFolha().getMes() == mes && dadosarquivo[i].getDataFolha().getAno() == ano)
                    {
                        verifica++;
                        // cout << "Folha j� foi calculada anteriormente." << endl;
                        break;
                    }
                }
            }

            if (verifica == 0 && folha.size() > 0)
            {
                for (int i = 0; i <= folha.size(); i++)
                {

                    if (folha[i].getDataFolha().getMes() == mes && folha[i].getDataFolha().getAno() == ano)
                    {
                        verifica++;
                        // cout << "Folha j� foi calculada anteriormente." << endl;
                        break;
                    }
                }
            }

            if (verifica == 0)
            {
                f.retornaFuncAtivos(registros, mes, ano);
                f.calcularFolhaMensal();
                folha.push_back(f);
                // folhaAnual.push_back(f);
                // cout << "A folha para o m�s foi calculada com sucesso.\n";
            }

            if (mes == 12)
            {
                break;
            }

            mes++;
        }
        // adiciona a folha anual depois de calculada no vector de folha anual
        FolhaSalarial fAnual;
        fAnual.calculaFolhaAnual(folha, ano);
        folhaAnual.push_back(fAnual);

        break;
    }
    case 5: // exibir folha salarial anual
    {
        aux = 0;
        int exibeAno = 0;
        double gastoAnual = 0;

        if (folhaAnual.size() > 0) // vreifica se a folha anual n�o est� vazia e exibe-a de acordo com o ano solicitado
        {
            for (int i = 0; i < folhaAnual.size(); i++)
            {
                if (folhaAnual[i].getDataFolha().getMes() == 0 && folhaAnual[i].getDataFolha().getAno() == ano)
                {
                    folhaAnual[i].exibeFolhaAnual();
                    aux++;
                    cout << endl
                         << endl
                         << endl;
                    break;
                }
            }
        }
        if (dadosarquivo.size() > 0) // Se a foha anual n�o estiver no vector de folhas anuais ent�o o programa vai procurar no vrctor dr dados
        {
            if (aux == 0)
            {
                system("cls");

                for (int i = 0; i < dadosarquivo.size(); i++)
                {

                    if (dadosarquivo[i].getDataFolha().getMes() == 0 && dadosarquivo[i].getDataFolha().getAno() == ano)
                    {
                        if (exibeAno == 0)
                        {
                            cout << "FOLHA REFERENTE AO ANO DE " << dadosarquivo[0].getDataFolha().getAno() << endl
                                 << endl;
                        }
                        exibeAno++;
                        gastoAnual += dadosarquivo[i].getSalarioBruto();

                        cout << "Nome: " << dadosarquivo[i].getNome() << "    ";

                        cout << "-    C�digo do Funcion�rio: " << dadosarquivo[i].getCodigoFunc() << endl;

                        cout << "Sal�rio bruto: R$ " << dadosarquivo[i].getSalarioBruto() << ", ";

                        cout << "Descontos dos Impostos: R$ " << (dadosarquivo[i].getImpostoRenda() + dadosarquivo[i].getInss()) << ", ";

                        cout << "Sal�rio l�quido: R$ " << dadosarquivo[i].getSalarioLiquido() << endl;

                        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        aux++;
                    }
                }
                cout << "\nGasto anual da empresa: R$ " << gastoAnual << endl << endl;
            }
        }

        if (aux == 0)
        {
            cout << "N�o existe Folha Anual a ser exibida." << endl;
        }

        break;
    }
    }
}

void Gerenciador::salvarArquivo() //salva as informa��es dos funcion�rios em um arquivo.txt
{
    fstream fs;

    fs.open("dados.txt", fstream::out | fstream::app);
    if (fs.is_open())
    {
        for (int i = 0; i < registros.size(); i++)
        {
            fs << registros[i]->getTipo() << endl;
            fs << registros[i]->getNome() << endl;
            fs << registros[i]->getEndereco().getRua() << endl;
            fs << registros[i]->getEndereco().getNumero() << endl;
            fs << registros[i]->getEndereco().getCep() << endl;
            fs << registros[i]->getEndereco().getCidade() << endl;
            fs << registros[i]->getEndereco().getBairro() << endl;
            fs << registros[i]->getEndereco().getEstado() << endl;
            fs << registros[i]->getTelefone() << endl;
            fs << registros[i]->getcpf() << endl;
            fs << registros[i]->getRg() << endl;
            fs << registros[i]->getCodigoFuncionario() << endl;
            fs << registros[i]->getSalario() << endl;
            fs << registros[i]->getDataIngresso().getMes() << endl;
            fs << registros[i]->getDataIngresso().getDia() << endl;
            fs << registros[i]->getDataIngresso().getAno() << endl;
            fs << registros[i]->getDataDemissao().getMes() << endl;
            fs << registros[i]->getDataDemissao().getDia() << endl;
            fs << registros[i]->getDataDemissao().getAno() << endl;

            if (registros[i]->getTipo() == 2)
            {
                fs << ((Gerente *)registros[i])->getAreaS() << endl;
            }
            if (registros[i]->getTipo() == 3)
            {
                fs << ((Diretor *)registros[i])->getAreaS() << endl;
                fs << ((Diretor *)registros[i])->getAreaF() << endl;
            }
            if (registros[i]->getTipo() == 4)
            {
                fs << ((Presidente *)registros[i])->getAreaFormacao() << endl;
                fs << ((Presidente *)registros[i])->getFormacaoAcademica() << endl;
            }
        }
        fs.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}

void Gerenciador::lerArquivo() // carrega no programa as informa�oes dos funcion�rios guardadas anteriormente no arquivo 
{
    Data dataIngresso, dataDemissao;
    Endereco endereco;
    int diaAd, mesAd, anoAd, diaD, mesD, anoD;
    double salario;
    string nome;
    string codigoF;
    string cpf;
    string rg;
    string rua, bairro, cidade, estado, cep, numero;
    string telefone;
    string areaSupervisao;
    string areaFormacao;
    string areaFormacaoMaxima;

    fstream fs;
    int tipo;
    Funcionario *f;
    fs.open("dados.txt", fstream::in);

    if (fs.is_open())
    {
        while (!fs.eof())
        {
            fs >> tipo;
            fs.ignore();
            getline(fs, nome);
            getline(fs, rua);
            getline(fs, numero);
            getline(fs, cep);
            getline(fs, cidade);
            getline(fs, bairro);
            getline(fs, estado);
            getline(fs, telefone);
            getline(fs, cpf);
            getline(fs, rg);
            getline(fs, codigoF);
            fs >> salario;
            fs >> mesAd;
            fs >> diaAd;
            fs >> anoAd;
            // consertar
            fs >> mesD;
            fs >> diaD;
            fs >> anoD;
            fs.ignore();
            endereco = Endereco(rua, numero, cep, cidade, bairro, estado);
            dataIngresso = Data(mesAd, diaAd, anoAd);
            dataDemissao = Data(mesD, diaD, anoD);

            if (fs.eof())
            {
                break;
            }

            switch (tipo)
            {
            case 1:

                f = new Operador(nome, endereco, telefone, cpf, rg, codigoF, salario, dataIngresso, dataDemissao);
                break;

            case 2:

                getline(fs, areaSupervisao);

                f = new Gerente(nome, endereco, telefone, cpf, rg, codigoF, salario, dataIngresso, dataDemissao, areaSupervisao);
                break;

            case 3:

                getline(fs, areaSupervisao);
                getline(fs, areaFormacao);

                f = new Diretor(nome, endereco, telefone, cpf, rg, codigoF, salario, dataIngresso, dataDemissao, areaSupervisao, areaFormacao);
                break;

            case 4:

                getline(fs, areaFormacao);
                getline(fs, areaFormacaoMaxima);

                f = new Presidente(nome, endereco, telefone, cpf, rg, codigoF, salario, dataIngresso, dataDemissao, areaFormacao, areaFormacaoMaxima);

                break;

            default:
                break;
            }
            registros.push_back(f);
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo." << endl;
    }
    fs.close();
}
void Gerenciador::deletaArquivo() // Deleta de funcion�rios para adicionar as informa��es sempre atualizadas
{
    fstream fs;

    fs.open("dados.txt", fstream::out);
    if (fs.is_open())
    {
        remove("dados.txt");
    }
    else
    {

        cout << "Arquivo n�o foi aberto corretamente." << endl;
    }
    fs.close();
}

int Gerenciador::retornaArquivoVazio(const char *file_name) // verifica se o arquivo passado como par�metro est� vazio
{
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

void Gerenciador::salvaArquivoFolha(int tipof) // Salva as informa��es das folhas mensais e anuais de acordo com o tipo passado como par�metro
{
    fstream fs;

    double salarioBruto;
    int cargaHoraria;
    int diasTrabalhados;
    double impostoRenda;
    double inss;
    double salarioLiquido;
    int mes, dia, ano; // dia = 1;

    if (tipof == 1)
    {
        fs.open("folha.txt", fstream::out | fstream::app);

        if (fs.is_open())
        {
            for (int i = 0; i < folha.size(); i++)
            {
                for (int j = 0; j < folha[i].retornaTamanhoVecDados(); j++)
                {
                    fs << folha[i].getDataFolha().getDia() << endl;
                    fs << folha[i].getDataFolha().getMes() << endl;
                    fs << folha[i].getDataFolha().getAno() << endl;
                    fs << folha[i].retornaDadosFunc(j).getNome() << endl;
                    fs << folha[i].retornaDadosFunc(j).getCodigoFunc() << endl;
                    fs << folha[i].retornaDadosFunc(j).getSalarioBruto() << endl;
                    fs << folha[i].retornaDadosFunc(j).getImpostoRenda() << endl;
                    fs << folha[i].retornaDadosFunc(j).getInss() << endl;
                    fs << folha[i].retornaDadosFunc(j).getSalarioLiquido() << endl;
                }
            }

            fs.close();
        }
        else
        {
            cout << "Arquivo n�o foi encontrado ou n�o pode ser aberto" << endl;
        }
    }
    if (tipof == 2)
    {
        fs.open("folha.txt", fstream::out | fstream::app);

        if (fs.is_open())
        {
            for (int i = 0; i < folhaAnual.size(); i++)
            {
                for (int j = 0; j < folhaAnual[i].retornaTamanhoVecDados(); j++)
                {
                    fs << folhaAnual[i].getDataFolha().getDia() << endl;
                    fs << folhaAnual[i].getDataFolha().getMes() << endl;
                    fs << folhaAnual[i].getDataFolha().getAno() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getNome() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getCodigoFunc() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getSalarioBruto() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getImpostoRenda() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getInss() << endl;
                    fs << folhaAnual[i].retornaDadosFunc(j).getSalarioLiquido() << endl;
                }
            }

            fs.close();
        }
        else
        {
            cout << "Arquivo n�o foi encontrado ou n�o pode ser aberto." << endl;
        }
    }
}

void Gerenciador::lerArquivoFolha() // Ler o arquivo de folhas para ser carregado no programa
{
    int dia, mes, ano; // dia = 1;
    string nome;
    string codigo;
    double salarioBruto;
    double impostoRenda;
    double inss;
    double salarioLiquido;
    DadosFolha d;

    fstream fs;
    int index = 0;
    DadosFolha dado;

    fs.open("folha.txt", fstream::in);

    if (fs.is_open())
    {
        while (!fs.eof())
        {

            fs >> dia;
            fs >> mes;
            fs >> ano;
            fs.ignore();
            getline(fs, nome);
            getline(fs, codigo);
            fs >> salarioBruto;
            fs >> impostoRenda;
            fs >> inss;
            fs >> salarioLiquido;

            dado.setDataFolha(Data(mes, dia, ano));
            dado.setNome(nome);
            dado.setCodigoFunc(codigo);
            dado.setSalarioBruto(salarioBruto);
            dado.setImpostoRenda(impostoRenda);
            dado.setInss(inss);
            dado.setSalarioLiquido(salarioLiquido);
            if (fs.eof())
            {
                break;
            }
            dadosarquivo.push_back(dado);
        }
    }
    fs.close();
}