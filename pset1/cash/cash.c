#include <cs50.h>
#include <stdio.h>

int calculate_minimum_coins(int change);

int main()
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    printf("%d\n", calculate_minimum_coins(change));
}

int calculate_minimum_coins(int change)
{
    const int price_25 = 25;
    const int price_10 = 10;
    const int price_5 = 5;
    const int price_1 = 1;
    int coin_count = 0;
    while (change > 0)
    {
        if (change >= price_25)
        {
            change -= price_25;
            coin_count++;
        }
        else if (change >= price_10)
        {
            change -= price_10;
            coin_count++;
        }
        else if (change >= price_5)
        {
            change -= price_5;
            coin_count++;
        }
        else if (change >= price_1)
        {
            change -= price_1;
            coin_count++;
        }
    }
    return coin_count;
}
