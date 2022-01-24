#include "helpers.h"
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
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

            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int calculatedRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int calculatedGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int calculatedBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (calculatedRed > 255)
            {
                calculatedRed = 255;
            }
            if (calculatedGreen > 255)
            {
                calculatedGreen = 255;
            }
            if (calculatedBlue > 255)
            {
                calculatedBlue = 255;
            }

            image[i][j].rgbtRed = calculatedRed;
            image[i][j].rgbtGreen = calculatedGreen;
            image[i][j].rgbtBlue = calculatedBlue;

        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
//Making temp array
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
            int sum_blue = 0;
            int sum_green = 0;
            int sum_red = 0;
            float avgCounter = 0;

//Edges
            //bottom right
            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                avgCounter++;
            }
            // bottom left
            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j - 1].rgbtRed;
                sum_green += temp[i][j - 1].rgbtGreen;
                sum_blue += temp[i][j - 1].rgbtBlue;
                avgCounter++;
            }
            //top left
            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i - 1][j].rgbtRed;
                sum_green += temp[i - 1][j].rgbtGreen;
                sum_blue += temp[i - 1][j].rgbtBlue;
                avgCounter++;
            }
            //top right
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i - 1][j - 1].rgbtRed;
                sum_green += temp[i - 1][j - 1].rgbtGreen;
                sum_blue += temp[i - 1][j - 1].rgbtBlue;
                avgCounter++;
            }

//Sides
            //bottom side
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j + 1].rgbtRed;
                sum_green += temp[i][j + 1].rgbtGreen;
                sum_blue += temp[i][j + 1].rgbtBlue;
                avgCounter++;
            }
            //top side
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i - 1][j + 1].rgbtRed;
                sum_green += temp[i - 1][j + 1].rgbtGreen;
                sum_blue += temp[i - 1][j + 1].rgbtBlue;
                avgCounter++;
            }
            //left side
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i + 1][j].rgbtRed;
                sum_green += temp[i + 1][j].rgbtGreen;
                sum_blue += temp[i + 1][j].rgbtBlue;
                avgCounter++;
            }
            //right side
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i + 1][j - 1].rgbtRed;
                sum_green += temp[i + 1][j - 1].rgbtGreen;
                sum_blue += temp[i + 1][j - 1].rgbtBlue;
                avgCounter++;
            }

//middle
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i + 1][j + 1].rgbtRed;
                sum_green += temp[i + 1][j + 1].rgbtGreen;
                sum_blue += temp[i + 1][j + 1].rgbtBlue;
                avgCounter++;
            }

            //calculations
            image[i][j].rgbtRed = round(sum_red / avgCounter);
            image[i][j].rgbtGreen = round(sum_green / avgCounter);
            image[i][j].rgbtBlue = round(sum_blue / avgCounter);
        }
    }
    return;
}

