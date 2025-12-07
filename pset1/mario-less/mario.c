#include <cs50.h>
#include <stdio.h>

void print_mario(int n); // prototype

int main()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // get input from user till they type 1 to 8
    print_mario(height);
}

void print_mario(int n) // function to print the mario
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
