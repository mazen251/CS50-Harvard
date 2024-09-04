#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // for each pixel check the intensity of each colour channel r,b,g
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            BYTE average = round((red + blue + green) / 3.0); // round fucntion was premitted to use from the "math.h" header file

            // Update pixel values to be the average (applying the gray scale filter)
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            int sepiaRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            int sepiaGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            int sepiaBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));


            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                 sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // (not to swap already swaped pixelssss)...........
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurredImage[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float redSum = 0;
            float greenSum = 0;
            float blueSum = 0;
            int pixelCount = 0;

            for (int yOffset = -1; yOffset <= 1; yOffset++)
            {
                for (int xOffset = -1; xOffset <= 1; xOffset++)
                {
                    int newRow = row + yOffset;
                    int newCol = col + xOffset;

                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        blueSum += image[newRow][newCol].rgbtBlue;
                        greenSum += image[newRow][newCol].rgbtGreen;
                        redSum += image[newRow][newCol].rgbtRed;
                        pixelCount++;
                    }
                }
            }

            blurredImage[row][col].rgbtBlue = round(blueSum / pixelCount);
            blurredImage[row][col].rgbtGreen = round(greenSum / pixelCount);
            blurredImage[row][col].rgbtRed = round(redSum / pixelCount);
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col].rgbtBlue = blurredImage[row][col].rgbtBlue;
            image[row][col].rgbtGreen = blurredImage[row][col].rgbtGreen;
            image[row][col].rgbtRed = blurredImage[row][col].rgbtRed;
        }
    }
}
