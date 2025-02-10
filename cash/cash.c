#include <cs50.h>
#include <stdio.h>

int calculate(int pay, int loop);
int sub(int count, int loop);

int main(void)
{
    int pay;
    do
    {
        pay = get_int("Change owed: ");
    }
    while (pay < 1);

    int loop = 1;
    int sum = 0;

    do
    {
        int count = calculate(pay, loop);
        sum += count;
        pay -= sub(count, loop);
        loop++;
    }
    while (pay > 0);

    printf("%i\n", sum);
}

int calculate(int pay, int loop)
{
    int divisao;
    switch (loop)
    {
        case 1:
            divisao = pay / 25;
            break;
        case 2:
            divisao = pay / 10;
            break;
        case 3:
            divisao = pay / 5;
            break;
        case 4:
            divisao = pay / 1;
            break;
    }

    return divisao;
}

int sub(int count, int loop)
{
    int valor;
    switch (loop)
    {
        case 1:
            valor = count * 25;
            break;
        case 2:
            valor = count * 10;
            break;
        case 3:
            valor = count * 5;
            break;
        case 4:
            valor = count * 1;
            break;
    }

    return valor;
}
