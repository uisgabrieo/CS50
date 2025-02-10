#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string nome;
    string numero;
}
pessoa;

int main(void)
{
    // string nomes[] = {"Luis", "Ana", "Lucas"};
    // string numeros[] = {"89-99431-0237", "86-99445-0790", "89-99410-1562"};

    pessoa pessoas[3];

    pessoas[0].nome = "Luis";
    pessoas[0].numero = "89-99431-0237";
    pessoas[1].nome = "Ana";
    pessoas[1].numero = "86-99445-0790";
    pessoas[2].nome = "Lucas";
    pessoas[2].numero = "89-99410-1562";

    string nome = get_string("Nome: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(pessoas[i].nome, nome) == 0)
        {
            printf("Número %s.\n", pessoas[i].numero);
            return 0;
        }
    }
    printf("Número não encontado.\n");
    return 1;
}
