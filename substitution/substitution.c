#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string key, string message);
int isLetter(string key);
int duplicateLetter(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2 || !isLetter(key) || duplicateLetter(key))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string send = encrypt(key, plaintext);

    printf("ciphertext: %s\n", send);
    return 0;
}

int duplicateLetter(string key)
{
    int length_key = strlen(key);
    for (int i = 0; i < length_key; i++)
    {
        for (int j = i + 1; j < length_key - i; j++)
        {
            if (key[i] == key[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int isLetter(string key)
{
    for (int i = 0, length_key = strlen(key); i < length_key; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }
    }
    return 1;
}

string encrypt(string key, string message)
{
    int size_message = strlen(message);
    char *new_message = malloc(size_message);

    for (int i = 0; i < size_message; i++)
    {
        if (isalpha(message[i]))
        {
            int a = islower(message[i]) ? 'a' : 'A';
            int index_letter = message[i] - a;
            switch (a)
            {
                case 'a':
                    new_message[i] = tolower(key[index_letter]);
                    break;
                case 'A':
                    new_message[i] = toupper(key[index_letter]);
                    break;
            }
        }
        else
        {
            new_message[i] = message[i];
        }
    }

    return new_message;
}
