#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find average of the RGB pixels
            float Blue = image[i][j].rgbtBlue;
            float Green = image[i][j].rgbtGreen;
            float Red = image[i][j].rgbtRed;
            int average = round((Blue + Green + Red) / 3);

            // Set RGB equal to the average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int counter = width - 1;
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j]; // Make a copy 
            image[i][j] = image[i][counter];
            image[i][counter] = temp;
            counter -= 1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
