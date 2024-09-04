#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string argument);
char rotate(char alpha, int n);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]) == 0)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        int n = strlen(plaintext);
        char ciphertext[n + 1]; // to include the '\0'

        printf("ciphertext: ");
        for (int i = 0; i < n; i++)
        {
            ciphertext[i] = rotate(plaintext[i], key);
            printf("%c", ciphertext[i]);
        }

        ciphertext[n] = '\0'; // properly terminated, could have been intialized as a string to save some overhead
        printf("\n");         // but, that was my intial thought and i stand by it :)
        

        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int only_digits(string argument)
{
    for (int i = 0, n = strlen(argument); i < n; i++)
    {
        if (!isdigit(argument[i]))
        {
            return 1; // other chars found
        }
    }
    return 0; // are digits
}

char rotate(char alpha, int n)
{
    if (alpha >= 'a' && alpha <= 'z')
    {
        return 'a' + (alpha - 'a' + n) % 26;
    }
    else if (alpha >= 'A' && alpha <= 'Z')
    {
        return 'A' + (alpha - 'A' + n) % 26;
    }
    else
    {
        return alpha; // Don't Encrypt any chars that are not alpha
    }
}
