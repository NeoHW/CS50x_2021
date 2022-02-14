#include <stdio.h>
#include <cs50.h>

int main(void)

{
    // prompt user for height 
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // print out pyramid
    for (int row = 0; row < height; row++)
    {
        //loop to add space
        for (int space = height - row; space > 1 ; space--)
        {
            printf(" ");
        }
        //loop to add left hex
        for (int hex = 0; hex <= row; hex++)
        {
            printf("#");
        }
        //loop to print 2 spaces
        printf("  ");
        //loop to add right hex
        for (int hexr = 0; hexr <= row ; hexr++)
        {
            printf("#");
        }
        printf("\n");
    }
}