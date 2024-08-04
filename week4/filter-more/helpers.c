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
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue, green, red;
            blue = green = red = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++) // FIND VALID SQUARES
            {
                for (int y = -1; y < 2; y++)
                {
                    int posX = i + x;
                    int posY = j + y;

                    if (posX < 0 || posX > (height - 1) || posY < 0 || posY > (width - 1))
                    {
                        continue;
                    }

                    blue +=
                        image[posX][posY].rgbtBlue; // Initalize the interger first in the beginning
                    green += image[posX][posY].rgbtGreen;
                    red += image[posX][posY].rgbtRed;
                    counter++;
                }

                temp[i][j].rgbtBlue = round(blue / counter);
                temp[i][j].rgbtGreen = round(green / counter);
                temp[i][j].rgbtRed = round(red / counter);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GX_RED = 0; // Initializing GX, GY values
            int GX_GREEN = 0;
            int GX_BLUE = 0;
            int GY_RED = 0;
            int GY_GREEN = 0;
            int GY_BLUE = 0;

            // Check for valid neighbouring squares
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int posX = i - 1 + x;
                    int posY = j - 1 + y;

                    if (posX < 0 || posX > (height - 1) || posY < 0 || posY > (width - 1))
                    {
                        continue; // Skip the adding if invalid which is same as adding zero
                    }
                    GX_RED += image[posX][posY].rgbtRed * GX[x][y];
                    GX_GREEN += image[posX][posY].rgbtGreen * GX[x][y];
                    GX_BLUE += image[posX][posY].rgbtBlue * GX[x][y];
                    GY_RED += image[posX][posY].rgbtRed * GY[x][y];
                    GY_GREEN += image[posX][posY].rgbtGreen * GY[x][y];
                    GY_BLUE += image[posX][posY].rgbtBlue * GY[x][y];
                }
            }

            // Compute each channel value as SQRT of Gx^2 + Gy^2
            int red = round(sqrt((GX_RED * GX_RED) + (GY_RED * GY_RED)));
            int green = round(sqrt((GX_GREEN * GX_GREEN) + (GY_GREEN * GY_GREEN)));
            int blue = round(sqrt((GX_BLUE * GX_BLUE) + (GY_BLUE * GY_BLUE)));

            if (red > 255)
            {
                red = 255;
            }

            if (green > 255)
            {
                green = 255;
            }

            if (blue > 255)
            {
                blue = 255;
            }

            temp[i][j].rgbtBlue = blue;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtRed = red;
        }
    }

    // Copy temp into image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
