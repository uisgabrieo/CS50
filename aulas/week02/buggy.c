#include <cs50.h>
#include <stdio.h>

void print_piramide(int height);

int main(void)
{
    int h = 3;
    print_piramide(h);
}

void print_piramide(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
