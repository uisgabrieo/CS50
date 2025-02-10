#include <cs50.h>
#include <stdio.h>

long sum_total(long num);
void select_card(long num);
int two_first_digits(long num);
int count_num(long num);

int main(void)
{
    long num_card = get_long("Numbers: ");

    if (sum_total(num_card) % 10 == 0)
    {
        select_card(num_card);
    }
    else
    {
        printf("INVALID\n");
    }
}

void select_card(long num)
{
    int size = count_num(num);
    int digits = two_first_digits(num);

    if ((size == 15) && (digits == 34 || digits == 37))
    {
        printf("AMEX\n");
    }
    else if ((size == 16 || size == 13) && (digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else if ((size == 16) && (digits >= 51 && digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int two_first_digits(long num)
{
    while (num >= 100)
    {
        num /= 10;
    }
    return num;
}

int count_num(long num)
{
    int size = 0;
    while (num > 0)
    {
        size++;
        num /= 10;
    }
    return size;
}

long sum_total(long num)
{
    int assistant = 0;
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        if (assistant)
        {
            digit *= 2;
            sum += (digit / 10) + (digit % 10);
        }
        else
        {
            sum += digit;
        }
        num /= 10;
        assistant = !assistant;
    }
    return sum;
}
