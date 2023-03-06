#include <ctype.h>
#include "../../C/cs50lib/cs50.h"
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//ASCII Table offsets
int ASCIIBottomOffset = 65;
int ASCIITopOffset = 90;

int compute_score(string word);
void print_winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    print_winner(score1, score2);
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); ++i)
    {
        char currentCharacter = word[i];

        if (islower(currentCharacter))
        {
            currentCharacter = toupper(currentCharacter);
        }

        int decimalCharRepresentation = (int)currentCharacter;

        if (decimalCharRepresentation >= ASCIIBottomOffset && decimalCharRepresentation <= ASCIITopOffset)
        {
            score += POINTS[decimalCharRepresentation - ASCIIBottomOffset];
        }
    }

    return score;
}

void print_winner(int score1, int score2)
{
    //Print a winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Player 2 wins!");
    }
}