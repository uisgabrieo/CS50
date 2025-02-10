#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_word(string word);
int calculete_score(int array_size, int index_letter[]);
int index_letter(char letter);

int main(void)
{
    string word_player_one = get_string("Player 1: ");
    string word_player_two = get_string("Player 2: ");

    int player_one_score = score_word(word_player_one);
    int player_two_score = score_word(word_player_two);

    if (player_one_score > player_two_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_one_score < player_two_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_word(string word)
{
    int len_word = strlen(word);
    int index_letter_word[len_word];

    for (int i = 0; i < len_word; i++)
    {
        index_letter_word[i] = index_letter(word[i]);
    }

    int score = calculete_score(len_word, index_letter_word);

    return score;
}

int index_letter(char letter)
{
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < 26; i++)
    {
        if (toupper(letter) == alphabet[i])
        {
            return i;
        }
    }
    return -1;
}

int calculete_score(int array_size, int index_letter[])
{
    int score = 0;
    int score_letter[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; i < array_size; i++)
    {
        if (index_letter[i] == -1)
        {
            continue;
        }
        score += score_letter[index_letter[i]];
    }
    return score;
}
