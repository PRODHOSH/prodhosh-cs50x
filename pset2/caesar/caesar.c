#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char list[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int alphabet;
    string plain = get_string("plaintext: ");
    char cipher[100];
    int key = atoi(argv[1]);
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            alphabet = plain[i] - 'A';
            cipher[i] = toupper(list[(alphabet + key ) % 26]);
        }
        else if (islower(plain[i]))
        {
            alphabet = plain[i] - 'a';
            cipher[i] = tolower(list[(alphabet + key) % 26]);
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[strlen(plain)] = '\0';

    printf("ciphertext: %s\n", cipher);
    return 0;
}
