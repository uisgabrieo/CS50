#include <stdio.h>

int main(void)
{
    int score1 = 10;
    int score2 = 20;
    int score3 = 30;
    int score4 = 40;

    int array[] = {score1, score2, score3, score4};
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", array[i]);
    }
}
