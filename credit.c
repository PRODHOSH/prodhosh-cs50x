#include <cs50.h>
#include <stdio.h>

int length_number(long number);
int check_sum(long number, int length);
string determine_card_type(int total, long number, int length);

int main()
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    int length = length_number(number);
    int total = check_sum(number, length);
    printf("%s\n", determine_card_type(total, number, length));
}

int length_number(long n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int check_sum(long number, int length)
{
    int digit;
    int sum_even = 0;
    int sum_odd = 0;

    for (int i = 1; i <= length; i++)
    {
        digit = number % 10;

        if (i % 2 == 0)
        {
            digit *= 2;
            sum_even += (digit / 10) + (digit % 10);
        }
        else
        {
            sum_odd += digit;
        }

        number /= 10;
    }

    return sum_even + sum_odd;
}

string determine_card_type(int total, long number, int length)
{
    if (total % 10 != 0)
    {
        return "INVALID";
    }

    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    int first_digit = start / 10;
    int first_two = start;

    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        return "AMEX";
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
