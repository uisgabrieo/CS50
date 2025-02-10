#include <stdio.h>
#include <stdlib.h>

// Lista encadeada que incrementa pelo final
typedef struct node
{
    int value;
    struct node *next;
} Node;

int main(int argc, char *argv[])
{
    printf("Linked List Sort\n");
    Node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        Node *n = malloc(sizeof(Node));
        if (n == NULL)
        {
            return 1;
        }
        n->value = atoi(argv[i]);
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else if (n->value < list->value)
        {
            n->next = list;
            list = n;
        }
        else
        {
            for (Node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                if (n->value < ptr->next->value)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    Node *ptr = list;
    while(ptr != NULL)
    {
        printf("Número: %i - Endereço%p\n", ptr->value, ptr->next);
        ptr=ptr->next;
    }
}
