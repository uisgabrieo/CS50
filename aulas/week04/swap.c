#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main()
{
    int a = 1;
    int b = 2;

    printf("Valor de A: %d\nValor de B: %d\n", a, b);
    // Endereço das variáveis
    swap(&a, &b);
    printf("Valor de A: %d\nValor de B: %d\n", a, b);
}

void swap(int *a, int *b)
{
    // desreferenciando os ponteiros
    int temp = *a;
    *a = *b;
    *b = temp;
}
