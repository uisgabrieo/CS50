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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

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
            float red_gx = 0, green_gx = 0, blue_gx = 0;
            float red_gy = 0, green_gy = 0, blue_gy = 0;

            red_gx += (pxs[i][j].rgbtRed * Gx[1][1]);
            red_gy += (pxs[i][j].rgbtRed * Gy[1][1]);
            green_gx += (pxs[i][j].rgbtGreen * Gx[1][1]);
            green_gy += (pxs[i][j].rgbtGreen * Gy[1][1]);
            blue_gx += (pxs[i][j].rgbtBlue * Gx[1][1]);
            blue_gy += (pxs[i][j].rgbtBlue * Gy[1][1]);

            if (i > 0)
            {
                red_gx += (pxs[i - 1][j].rgbtRed * Gx[0][1]);
                red_gy += (pxs[i - 1][j].rgbtRed * Gy[0][1]);
                green_gx += (pxs[i - 1][j].rgbtGreen * Gx[0][1]);
                green_gy += (pxs[i - 1][j].rgbtGreen * Gy[0][1]);
                blue_gx += (pxs[i - 1][j].rgbtBlue * Gx[0][1]);
                blue_gy += (pxs[i - 1][j].rgbtBlue * Gy[0][1]);
            }
            if (i > 0 && j > 0)
            {
                red_gx += (pxs[i - 1][j - 1].rgbtRed * Gx[0][0]);
                red_gy += (pxs[i - 1][j - 1].rgbtRed * Gy[0][0]);
                green_gx += (pxs[i - 1][j - 1].rgbtGreen * Gx[0][0]);
                green_gy += (pxs[i - 1][j - 1].rgbtGreen * Gy[0][0]);
                blue_gx += (pxs[i - 1][j - 1].rgbtBlue * Gx[0][0]);
                blue_gy += (pxs[i - 1][j - 1].rgbtBlue * Gy[0][0]);
            }
            if (i > 0 && j < width - 1)
            {
                red_gx += (pxs[i - 1][j + 1].rgbtRed * Gx[0][2]);
                red_gy += (pxs[i - 1][j + 1].rgbtRed * Gy[0][2]);
                green_gx += (pxs[i - 1][j + 1].rgbtGreen * Gx[0][2]);
                green_gy += (pxs[i - 1][j + 1].rgbtGreen * Gy[0][2]);
                blue_gx += (pxs[i - 1][j + 1].rgbtBlue * Gx[0][2]);
                blue_gy += (pxs[i - 1][j + 1].rgbtBlue * Gy[0][2]);
            }

            if (i < height - 1)
            {
                red_gx += (pxs[i + 1][j].rgbtRed * Gx[2][1]);
                red_gy += (pxs[i + 1][j].rgbtRed * Gy[2][1]);
                green_gx += (pxs[i + 1][j].rgbtGreen * Gx[2][1]);
                green_gy += (pxs[i + 1][j].rgbtGreen * Gy[2][1]);
                blue_gx += (pxs[i + 1][j].rgbtBlue * Gx[2][1]);
                blue_gy += (pxs[i + 1][j].rgbtBlue * Gy[2][1]);
            }
            if (i < height - 1 && j > 0)
            {
                red_gx += (pxs[i + 1][j - 1].rgbtRed * Gx[2][0]);
                red_gy += (pxs[i + 1][j - 1].rgbtRed * Gy[2][0]);
                green_gx += (pxs[i + 1][j - 1].rgbtGreen * Gx[2][0]);
                green_gy += (pxs[i + 1][j - 1].rgbtGreen * Gy[2][0]);
                blue_gx += (pxs[i + 1][j - 1].rgbtBlue * Gx[2][0]);
                blue_gy += (pxs[i + 1][j - 1].rgbtBlue * Gy[2][0]);
            }
            if (i < height - 1 && j < width - 1)
            {
                red_gx += (pxs[i + 1][j + 1].rgbtRed * Gx[2][2]);
                red_gy += (pxs[i + 1][j + 1].rgbtRed * Gy[2][2]);
                green_gx += (pxs[i + 1][j + 1].rgbtGreen * Gx[2][2]);
                green_gy += (pxs[i + 1][j + 1].rgbtGreen * Gy[2][2]);
                blue_gx += (pxs[i + 1][j + 1].rgbtBlue * Gx[2][2]);
                blue_gy += (pxs[i + 1][j + 1].rgbtBlue * Gy[2][2]);
            }

            if (j < width - 1)
            {
                red_gx += (pxs[i][j + 1].rgbtRed * Gx[1][2]);
                red_gy += (pxs[i][j + 1].rgbtRed * Gy[1][2]);
                green_gx += (pxs[i][j + 1].rgbtGreen * Gx[1][2]);
                green_gy += (pxs[i][j + 1].rgbtGreen * Gy[1][2]);
                blue_gx += (pxs[i][j + 1].rgbtBlue * Gx[1][2]);
                blue_gy += (pxs[i][j + 1].rgbtBlue * Gy[1][2]);
            }
            if (j > 0)
            {
                red_gx += (pxs[i][j - 1].rgbtRed * Gx[1][0]);
                red_gy += (pxs[i][j - 1].rgbtRed * Gy[1][0]);
                green_gx += (pxs[i][j - 1].rgbtGreen * Gx[1][0]);
                green_gy += (pxs[i][j - 1].rgbtGreen * Gy[1][0]);
                blue_gx += (pxs[i][j - 1].rgbtBlue * Gx[1][0]);
                blue_gy += (pxs[i][j - 1].rgbtBlue * Gy[1][0]);
            }

            int red = round(sqrt(pow(red_gx, 2) + pow(red_gy, 2)));
            int blue = round(sqrt(pow(blue_gx, 2) + pow(blue_gy, 2)));
            int green = round(sqrt(pow(green_gx, 2) + pow(green_gy, 2)));
            image[i][j].rgbtRed = (int) fmin(255, red);
            image[i][j].rgbtGreen = (int) fmin(255, green);
            image[i][j].rgbtBlue = (int) fmin(255, blue);
        }
    }
}
