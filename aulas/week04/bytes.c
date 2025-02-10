#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    char *file = argv[1];

    FILE *f = fopen(file, "r");

    uint16_t buffer[4];
    fread(buffer, 1, 4, f);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    fclose(f);
}
