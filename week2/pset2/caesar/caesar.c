#include <ctype.h>
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


string get_ciphertext(void);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    // check if there are only digits
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0) // if there are non digits, printf ... (false is 0)
            {
                printf("usage: ./caesar key\n");
                return 1;
            }
        }
        // switch input from string to an int
        int input = atoi(argv[1]);
        
        //print below commands for checking purposes
        
        
        //printf("Success\n");
        //printf("%i\n", input);
        
        // get plaintext
        string plaintext = get_string("plaintext: ");
        
        // get ciphertext
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isupper(plaintext[i]))
            {
                // convert ASCII to aplhabetical index (e.g. 0), shift index using formula, convert back to ASCII
                printf("%c", (((plaintext[i] + input) - 65) % 26) + 65); 
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + input) - 97) % 26) + 97);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
