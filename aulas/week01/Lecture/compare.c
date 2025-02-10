#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");

    if(x < y)
    {
        printf("%i maior que %i", y, x);
    }
    else if(y < x)
    {
        printf("%i maior que %i", x, y);
    }
    else
    {
        printf("%i igual a %i", x, y);
    }
}
