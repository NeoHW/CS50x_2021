#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            float average = (((float)red + green + blue) / 3);  // need to float either RGB so that avg can be float
            average = round(average);
            
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            float sepiaRed = round((red * .393) + (green * .769) + (blue * .189));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            float sepiaGreen = round((red * .349) + (green * .686) + (blue * .168));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            float sepiaBlue = round((red * .272) + (green * .534) + (blue * .131));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width / 2; j++) // integers at 0.5 will round DOWN. e.g. 7/2 = 3.5 = 3
        {
            RGBTRIPLE temp; // use this for the whole pixel as no need indiv RGB
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create temp image to store blurred image
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalred = 0;
            int totalgreen = 0;
            int totalblue = 0;
            float counter = 0.00; // to make sure later when dividing answer is a float
            
            for (int y = -1; y < 2; y++) // from neighbouring top to btm pixels
            {
                for (int x = -1; x < 2; x++) // get neighbouring left n right pixels for each pixel in line 88
                {
                    int currentY = i + y;
                    int currentX = j + x;
                    
                    // if current pixels "outside" image, skip and continue the loop
                    if (currentY < 0 || currentY > (height - 1) || currentX < 0 || currentX > (width - 1))
                    {
                        continue;
                    }
                    // get image RGB values
                    totalred += image[currentY][currentX].rgbtRed;
                    totalgreen += image[currentY][currentX].rgbtGreen;
                    totalblue += image[currentY][currentX].rgbtBlue;
                    
                    //count how many pixels added
                    counter++;
                }
            }
            // store in temp if not next few steps will use blurred pixels instead of original pixels
            temp[i][j].rgbtRed = round(totalred / counter); // counter is float so output will be float
            temp[i][j].rgbtGreen = round(totalgreen / counter);
            temp[i][j].rgbtBlue = round(totalblue / counter);
        }
    }
    
    // copy each pixel from blurred temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}