// preprocessor directives

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototypes

int calculate_grade(int, int, int);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// main function

int main()
{
    string text = get_string("Text: "); // gets string from user
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = calculate_grade(letters, words, sentences);

    // conditions to print the grade

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int count_letters(string text) // function counts the no of letters and returns
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (toupper(text[i]) >= 65 &&
            toupper(text[i]) <= 90) // checks if character is from A TO Z. here using ASCII values
        {
            count++;
        }
    }
    return count;
}

int count_words(string text) // function counts the no of words and returns
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text) // function counts the no of sentences and returns
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
int calculate_grade(int letters, int words,
                    int sentences) // calculates the grade and rounds and returns finally
{
    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    float index = 0.0588 * L - 0.296 * S - 15.8; // the Coleman-Liau index formula
    index = round(index);
    return (int) index;
}
