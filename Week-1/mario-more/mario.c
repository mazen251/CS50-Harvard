#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    int spaces = height - 1;

    for (int i = 1; i <= height; i++)
    {
        for (int k = spaces; k > 0; k--)
        {
            printf(" ");
        }

        for (int j = 0; j < i * 2; j++)
        {
            if (j == ((i * 2) / 2))
            {
                printf("  ");
                printf("#");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
        spaces--;
    }
}
