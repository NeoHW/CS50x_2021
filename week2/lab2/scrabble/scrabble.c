#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int sum = 0;
    int num = 0;


    for (int i = 0, n = strlen(word); i < n; i++)
    {

        int lowercase = tolower(word[i]);
        // computer using POINTS array, return the score for he string argument. Chars which are not letters should be given 0 points (loop is not closed!)
        if ('a' <= lowercase && lowercase <= 'z') // for a- z
        {
            num = (lowercase - 97);
            //97 is acsii code for 'a'(this is to get the values from 0-25, which is letters corresponding to point array)
            num = POINTS[num];
        }
        else // for puncuation or special characters
        {
            num = 0;
        }
        sum += num;
    }

    return sum;
}