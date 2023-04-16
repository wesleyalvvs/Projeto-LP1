//Implementa��o dos m�todos isDigit() e isLetter()
//Usando a ISO 8859-1 para comseguir manipular caractereres acentuados
#include "VerificaCaractere.h"
#include <string>

int isDigit(std::string nome)
{
    int verifica = nome.size();
    for (int i = 0; i < nome.size(); i++)
    {
        if (nome[i] >= '0' && nome[i] <= '9')
            verifica--;
    }

    if (verifica == 0)
    {
        return 1;
    }

    return 0;
}

int isLetter(std::string nome)
{
    int verifica = nome.size();
    for (int i = 0; i < nome.size(); i++)
    {
        // est�o incluidos os caracteres comuns e, como utilizamos a 'ISO 8859-1'e o 'setlocale(LC_ALL, "Portuguese")', inclu�mos caracteres de acentua��o
        if (nome[i] >= 'a' && nome[i] <= 'z' || nome[i] >= 'A' && nome[i] <= 'Z' || nome[i] == ' ' || nome[i] >= '�' && nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�' || nome[i] <= '�')
            verifica--;
    }

    if (verifica == 0)
    {
        return 1;
    }

    return 0;
}