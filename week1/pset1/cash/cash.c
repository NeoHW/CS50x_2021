#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    // Prompt user for amount of change
    float dollars;
    do
    {
        dollars = get_float("cash owed:");
    }
    while(dollars < 0);

    // Convert dollars to cents & round it
    int cents = round(dollars * 100);

    // keep track of change, and how many coins used
    int coins = 0;
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
        }
        else if (cents >= 1)
        {
            cents = cents - 1;
        }
        coins++;
    }
    // Print number of coins
    printf("%i\n", coins);
}