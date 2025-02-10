#include <cs50.h>
#include <stdio.h>

int main()
{

    int n = 50;
    int *p = &n;
    char *j = "Hi";
    printf("Endereço de N: %p\n", &n);
    printf("Endereço de N por P: %p\n", p);
    printf("Endereço de P: %p\n", &p);
    printf("Valor de N por P: %i\n", *p);
    printf("Valor de J: %i\n", *j);

    int* a, b;
    a = &n;
    b = 5;

    printf("A: %p\n", a);
    printf("B: %i\n", b);


}
