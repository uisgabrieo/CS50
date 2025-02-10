#include <stdio.h>

int main(void)
{
    // int tam_y;
    // int tam_x;

    // scanf("%i", &tam_y);
    // scanf("%i", &tam_x);
    int n;
    do
    {
        printf("Insita um número: \n");
        scanf("%d", &n);
    }
    while(n < 1);

    // const int n = 5;
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
