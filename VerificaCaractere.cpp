//Implementação dos métodos isDigit() e isLetter()
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
        // estão incluidos os caracteres comuns e, como utilizamos a 'ISO 8859-1'e o 'setlocale(LC_ALL, "Portuguese")', incluímos caracteres de acentuação
        if (nome[i] >= 'a' && nome[i] <= 'z' || nome[i] >= 'A' && nome[i] <= 'Z' || nome[i] == ' ' || nome[i] >= 'À' && nome[i] <= 'ÿ' || nome[i] <= 'á' || nome[i] <= 'â' || nome[i] <= 'ã' || nome[i] <= 'é' || nome[i] <= 'ê' || nome[i] <= 'ó' || nome[i] <= 'ô' || nome[i] <= 'õ' || nome[i] <= 'í' || nome[i] <= 'ç')
            verifica--;
    }

    if (verifica == 0)
    {
        return 1;
    }

    return 0;
}