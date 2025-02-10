#include <cs50.h>
#include <stdio.h>

#include <string.h>

int main(void)
{
    // int array[] = {20, 500, 10, 5, 100, 1, 50};

    // int num = get_int("Numero: ");

    // for (int i = 0; i < 7; i++)
    // {
    //     if (array[i] == num)
    //     {
    //         printf("Número %i encontado.\n", num);
    //         return 0;
    //     }
    // }
    // printf("Número não encontrado.");
    // return 1;
    string array[] = {20, 500, 10, 5, 100, 1, 50};

    string s = get_string("Palavra: ");

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(array[i], s) == 0)
        {
            printf("Palavra '%s' encontado.\n", s);
            return 0;
        }
    }
    printf("Palavra não encontrada.");
    return 1;
}
