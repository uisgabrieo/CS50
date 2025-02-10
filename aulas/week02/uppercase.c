#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string entrada = get_string("Entrada: ");
    printf("Saida:   ");

    for (int i = 0, n = strlen(entrada); i < n; i++)
    {
        // if (entrada[i] >= 'a' && entrada[i] <= 'z')
        // {
            // int uppercase = entrada[i] - 32;
            printf("%c", toupper(entrada[i]));
        // }
        // else
        // {
        //     printf("%c", entrada[i]);
        // }
    }
    printf("\n");
}
