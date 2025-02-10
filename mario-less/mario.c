#include <cs50.h>
#include <stdio.h>

void print_bricks(int s, int n);

int main(void)
{
    int height;

    do
    {
        height = get_int("Heigth: ");
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
    {
        print_bricks(height - (i + 1), i + 1);
    }
}

void print_bricks(int s, int n)
{
    for (int j = 0; j < s; j++)
    {
        printf(" ");
    }
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
