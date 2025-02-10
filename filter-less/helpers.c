#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *px = &image[i][j];

            int avg = round(((*px).rgbtRed + (*px).rgbtBlue + (*px).rgbtGreen) / 3.0);

            (*px).rgbtRed = (*px).rgbtGreen = (*px).rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *px = &image[i][j];

            float r = round(((*px).rgbtRed * 0.393) + ((*px).rgbtGreen * 0.769) +
                            ((*px).rgbtBlue * 0.189));
            float g = round(((*px).rgbtRed * 0.349) + ((*px).rgbtGreen * 0.686) +
                            ((*px).rgbtBlue * 0.168));
            float b = round(((*px).rgbtRed * 0.272) + ((*px).rgbtGreen * 0.534) +
                            ((*px).rgbtBlue * 0.131));
            (*px).rgbtRed = (int) fmin(255, r);
            (*px).rgbtGreen = (int) fmin(255, g);
            (*px).rgbtBlue = (int) fmin(255, b);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE *px = &image[i][j];
            RGBTRIPLE *px_ = &image[i][width - j - 1];

            RGBTRIPLE temp = *px;
            (*px) = (*px_);
            (*px_) = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pxs[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pxs[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0, green = 0, blue = 0, count = 0.0;

            red += pxs[i][j].rgbtRed;
            green += pxs[i][j].rgbtGreen;
            blue += pxs[i][j].rgbtBlue;
            count++;

            if (i > 0)
            {
                red += pxs[i - 1][j].rgbtRed;
                green += pxs[i - 1][j].rgbtGreen;
                blue += pxs[i - 1][j].rgbtBlue;
                count++;
            }
            if (i > 0 && j > 0)
            {
                red += pxs[i - 1][j - 1].rgbtRed;
                green += pxs[i - 1][j - 1].rgbtGreen;
                blue += pxs[i - 1][j - 1].rgbtBlue;
                count++;
            }
            if (i > 0 && j < width - 1)
            {
                red += pxs[i - 1][j + 1].rgbtRed;
                green += pxs[i - 1][j + 1].rgbtGreen;
                blue += pxs[i - 1][j + 1].rgbtBlue;
                count++;
            }

            if (i < height - 1)
            {
                red += pxs[i + 1][j].rgbtRed;
                green += pxs[i + 1][j].rgbtGreen;
                blue += pxs[i + 1][j].rgbtBlue;
                count++;
            }
            if (i < height - 1 && j > 0)
            {
                red += pxs[i + 1][j - 1].rgbtRed;
                green += pxs[i + 1][j - 1].rgbtGreen;
                blue += pxs[i + 1][j - 1].rgbtBlue;
                count++;
            }
            if (i < height - 1 && j < width - 1)
            {
                red += pxs[i + 1][j + 1].rgbtRed;
                green += pxs[i + 1][j + 1].rgbtGreen;
                blue += pxs[i + 1][j + 1].rgbtBlue;
                count++;
            }

            if (j < width - 1)
            {
                red += pxs[i][j + 1].rgbtRed;
                green += pxs[i][j + 1].rgbtGreen;
                blue += pxs[i][j + 1].rgbtBlue;
                count++;
            }
            if (j > 0)
            {
                red += pxs[i][j - 1].rgbtRed;
                green += pxs[i][j - 1].rgbtGreen;
                blue += pxs[i][j - 1].rgbtBlue;
                count++;
            }


            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
}
