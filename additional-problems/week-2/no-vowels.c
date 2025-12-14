// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string user);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string user = argv[1];
    printf("%s\n", replace(user));
    return 0;
}

string replace(string user)
{
    for (int i = 0, n = strlen(user); i < n; i++)
    {
        char choice = user[i];
        switch(choice)
        {
            case 'a':
                user[i] = '6';
                break;
            case 'e':
                user[i] = '3';
                break;
            case 'i':
                user[i] = '1';
                break;
            case 'o':
                user[i] = '0';
                break;
            case 'u':
                break;
            default:
                break;
        }
    }
    return user;
}
