#include <stdio.h>
#include <stdlib.h>

int main()
{
    //  int list[3];
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;
    free(list);
    list = tmp;

    //LIST
    for (int i = 0; i < 4; i++)
    {
        printf("%i - %p\n", list[i], &list[i]);
    }

    printf("\n");

    //TMP
    for (int i = 0; i < 4; i++)
    {
        printf("%i - %p\n", tmp[i], &tmp[i]);
    }

    printf("\n");
    free(list);

    //TMP
    for (int i = 0; i < 4; i++)
    {
        printf("%i - %p\n", tmp[i], &tmp[i]);
    }
}
