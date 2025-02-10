// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Variable global
unsigned int word_count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    if (table[hash_value] == NULL)
    {
        return false;
    }

    for (node *pnt = table[hash_value]; pnt != NULL; pnt = pnt->next)
    {
        if (strcasecmp(word, pnt->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        hash_value += tolower(word[i]);
    }

    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fgets(word, sizeof(word), dict))
    {
        word[strcspn(word, "\n")] = '\0';
        if (!isalpha(*word))
        {
            continue;
        }

        node *node_word = malloc(sizeof(node));

        if (node_word == NULL)
        {
            fclose(dict);
            return false;
        }

        int hash_value = hash(word);

        strcpy(node_word->word, word);
        node_word->next = NULL;

        if (table[hash_value] == NULL)
        {
            table[hash_value] = node_word;
        }
        else
        {
            node_word->next = table[hash_value];
            table[hash_value] = node_word;
        }

        word_count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *hash_node = table[i];
        if (hash_node == NULL)
        {
            continue;
        }

        while (hash_node != NULL)
        {
            node *temp = hash_node;
            hash_node = hash_node->next;
            free(temp);
        }
        table[i] = NULL;
    }

    return true;
}
