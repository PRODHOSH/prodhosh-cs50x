#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char list[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    char cipher[100];
    int alphabet;

    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            for (int j = i + 1; j < 26; j++)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    string plain = get_string("plaintext: ");

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            alphabet = plain[i] - 'A';
            cipher[i] = toupper(argv[1][alphabet]);
        }
        else if (islower(plain[i]))
        {
            alphabet = plain[i] - 'a';
            cipher[i] = tolower(argv[1][alphabet]);
        }
        else if (isdigit(plain[i]) || ispunct(plain[i]) || isblank(plain[i]))
        {
            cipher[i] = plain[i];
        }
    }

    printf("ciphertext: %s\n", cipher);
    return 0;
}
