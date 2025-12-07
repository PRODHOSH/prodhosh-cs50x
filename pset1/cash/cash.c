#include <cs50.h>
#include <stdio.h>

int greedy_algorithm(int change);

int main()
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while(change < 0);
    printf("%d\n", greedy_algorithm(change));
}

int greedy_algorithm(int change)
{
    int price_25 = 25;
    int price_10 = 10;
    int price_5 = 5;
    int price_1 = 1;
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
        else
        {
            coin_count++;
        }
    }
    return coin_count;
}
