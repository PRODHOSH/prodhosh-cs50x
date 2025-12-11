#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string player);               
string determine_winner(int player1, int player2);

const int array[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3, 
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main()
{
    string player_1 = get_string("Player 1: "); 
    string player_2 = get_string("Player 2: "); 
    int player1_points = calculate_score(player_1);
    int player2_points = calculate_score(player_2);
    printf("%s\n", determine_winner(player1_points, player2_points)); 
    return 0;
}

int calculate_score(string player) 
{
    int score = 0;
    for (int i = 0, n = strlen(player); i < n; i++)
    {
        char letter = toupper(player[i]);
        score += array[letter - 'A']; 
    }
    return score; 
}

string determine_winner(int player1, int player2) 
{
    if (player1 > player2)
    {
        return "Player 1 wins!"; 
    }
    else if (player1 < player2)
    {
        return "Player 2 wins!";
    }
    else
    {
        return "Tie!";
    }
}
