#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *right;
    struct node *left;
} Node;

int search(Node *tree, int number);

int main()
{
    //Criar árvore
}

bool search(Node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->value)
    {
        return search(tree->left, number);
    }
    else if (number > tree->value)
    {
        return search(tree->rigth, number);
    }
    else if (number == tree->value)
    {
        return true;
    }
    return false;

}
