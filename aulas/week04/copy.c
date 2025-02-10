#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);
    // char *t = s;

    // if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("t: %s\n", t);
    printf("s: %s\n", s);

    free(t);
    return 0;
}
