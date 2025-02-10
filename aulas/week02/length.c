#include <cs50.h>
#include <stdio.h>
#include <string.h>

// int length(string word);

int main(void)
{
    string nome = get_string("Nome: ");
    printf("%li\n", strlen(nome));

}

// int length(string word)
// {
//     int n = 0;

//     while(word[n] != '\0')
//     {
//         n++;
//     }
//     return n;
// }
