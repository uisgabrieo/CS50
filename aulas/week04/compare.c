#include <cs50.h>
#include <stdio.h>

int main()
{
    char *i = get_string("i: ");
    char *j = get_string("j: ");
    // int i = get_int("i: ");
    // int j = get_int("j: ");

    if (*i == *j)
    {
        printf("Iguais\n");
    }
    else
    {
        printf("Diferentes\n");
    }
}
