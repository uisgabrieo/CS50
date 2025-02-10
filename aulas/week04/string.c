#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "Hi!";
    printf("Ponteiro S: %p\n", s);

    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", s[i]);
    }

    printf("\n");

    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", *(s + i));
    }
}
