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
    while (height < 1 || height > 8); // getting height until valid input
    print_mario(height); // print mario function
    return 0;
}

void print_mario(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
