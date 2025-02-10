#include <stdio.h>
#include <stdlib.h>

//Lista encadeada que incrementa pelo começo
typedef struct node
{
    int value;
    struct node *next;
} Node;

int main(int argc, char *argv[])
{
    printf("Linked List Start\n");
    Node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        Node *n = malloc(sizeof(Node));
        if (n == NULL)
        {
            return 1;
        }
        n->value = atoi(argv[i]);
        n->next = list;
        list = n;
    }

    Node *ptr = list;
    while(ptr != NULL)
    {
        printf("Número: %i - Endereço%p\n", ptr->value, ptr->next);
        ptr=ptr->next;
    }
}
