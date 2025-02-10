#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Hello");
    string res = get_string("Qual o seu nome? ");
    printf("Olá, %s", res);
}
