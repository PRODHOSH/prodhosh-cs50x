// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int uppercase = 0, lowercase = 0, number = 0, symbol = 0;
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        char choice = password[i];
        if (isupper(choice))
            uppercase += 1;
        else if (islower(choice))
            lowercase += 1;
        else if (isdigit(choice))
            number += 1;
        else
            symbol += 1;
    }
    if (uppercase == 0 || lowercase == 0 || number == 0 || symbol == 0)
    {
        return false;
    }
    else
        return true;
}
