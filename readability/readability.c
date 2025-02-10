#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int calculate_grade(int letters, int words, int sentences);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int grade = calculate_grade(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int calculate_grade(int letters, int words, int sentences)
{
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return (int) round(index);
}

int count_letters(string text)
{
    int count = 0;
    int aux = 0;
    while (text[aux] != '\0')
    {
        if (isalpha(text[aux]))
        {
            count++;
        }
        aux++;
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    int aux = 0;
    while (text[aux] != '\0')
    {
        if (isblank(text[aux]) || text[aux + 1] == '\0')
        {
            count++;
        }
        aux++;
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int aux = 0;
    while (text[aux] != '\0')
    {
        if (text[aux] == '!' || text[aux] == '?' || text[aux] == '.')
        {
            count++;
        }
        aux++;
    }
    return count;
}
