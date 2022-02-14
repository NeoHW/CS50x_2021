#include <ctype.h>
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get input from user
    string text = get_string("Text: ");
    
    // Print number of letters
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    
    // Print number of words ( only those separated by a space to be counted)
    int words = 1; // no. of words = no. of spaces + 1
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words ++;
        }
    }
    
    // Print out number of sentences (./?/! means one sentence)
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    
    // Grade the text ( index = 0.0588 * L - 0.296 * S - 15.8) & round
    double L = ((float)letters / (float)words) * 100;
    double S = ((float)sentences / (float)words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // Print the grade out
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}