#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string key_string, string message);
int isNumeric(string arg);

int main(int argc, string argv[])
{
    if (argc != 2 || !isNumeric(argv[1]))
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    string send = encrypt(key, plaintext);

    printf("ciphertext: %s\n", send);
    return 0;
}

int isNumeric(string arg)
{
    for (int i = 0, length = strlen(arg); i < length; i++)
    {
        if (!isdigit(arg[i]))
        {
            return 0;
        }
    }
    return 1;
}

string encrypt(string key_string, string message)
{
    int key = atoi(key_string);
    int size_message = strlen(message);
    char *new_message = malloc(size_message + 1);

    for (int i = 0; i < size_message; i++)
    {
        if (isalpha(message[i]))
        {
            int a = islower(message[i]) ? 'a' : 'A';
            int new_letter = (((message[i] - a) + key) % 26) + a;
            new_message[i] = new_letter;
        }
        else
        {
            new_message[i] = message[i];
        }
    }

    return new_message;
}
