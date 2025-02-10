#include <cs50.h>
#include <stdio.h>

void print_bricks(int s, int n);
void bricks(int b);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
    {
        print_bricks(height - (i + 1), i + 1);
    }
}

void print_bricks(int s, int b)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }
    bricks(b);
    printf("  ");
    bricks(b);
    printf("\n");
}

void bricks(int b)
{
    for (int j = 0; j < b; j++)
    {
        printf("#");
    }
}
