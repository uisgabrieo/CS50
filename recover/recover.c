#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BLOCKS = 512;
typedef uint8_t BYTE;

int fourByte(int byte);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char *file_name = argv[1];
    FILE *input = fopen(file_name, "r");
    if (input == NULL)
    {
        return 1;
    }

    BYTE *buffer = malloc(BLOCKS);
    char name[8];
    FILE *output = NULL;
    int count = 0;

    while (fread(buffer, BLOCKS, 1, input))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && fourByte(buffer[3]))
        {
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(name, "%03i.jpg", count);
            output = fopen(name, "a");
            if (output == NULL)
            {
                fclose(input);
                return 1;
            }
            fwrite(buffer, BLOCKS, 1, output);
            count++;
        }
        else
        {
            if (output != NULL)
            {
                fwrite(buffer, BLOCKS, 1, output);
            }
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);

    free(buffer);
}

int fourByte(int byte)
{
    if (byte >= 0xe0 && byte <= 0xef)
    {
        return 1;
    }
    return 0;
}
