 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *input_pointer = fopen(argv[1], "r");
    if (input_pointer == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    
    BYTE block[BLOCK_SIZE]; // creating an array of 512 bytes
    int counter = 0;
    char filename[8];  // string with char array of 7 + 1 = 8 (000.jpg) and \n
    FILE *img = NULL;   // img = file pointer we will write to
    
    while (fread(block, BLOCK_SIZE, 1, input_pointer) == 1) // if it dosent read 1 block of 255 at end , fread will return <1.
    {
        // check if header by checking first 4 bytes
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0) // how to use bitwise arithmetic &?
        {
            if (counter == 0)
            {
                //naming the outfile
                sprintf(filename, "%03i.jpg", counter);
                counter ++;
            
                //open new outfile for writing
                img = fopen(filename, "w");
            
                // write to outfile
                fwrite(block, BLOCK_SIZE, 1, img);
            }
        
            else if (counter > 0)
            {
                // close current open file
                fclose(img);
            
                // name new outfile
                sprintf(filename, "%03i.jpg", counter);
                counter ++;
            
                // open new outfile
                img = fopen(filename, "w");
            
                // write to new outfile
                fwrite(block, BLOCK_SIZE, 1, img);
            }
        }
        else if (counter > 0)
        {
            fwrite(block, BLOCK_SIZE, 1, img);
        }
    }
    fclose(img);
    fclose(input_pointer);
    
    return 0;
}