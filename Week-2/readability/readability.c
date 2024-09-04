#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string word);
int words(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // printf("Letters in text are %i letters. \n ", letters(text));
    // printf("Words in text are %i words. \n ", words(text));
    // printf("sentences in text are %i sentence. \n ", sentences(text));

    int letter_count = letters(text);
    int word_count = words(text);
    int sentence_count = sentences(text);

    float L = (float) letter_count / word_count * 100;
    float S = (float) sentence_count / word_count * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int letters(string word)
{
    int count = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            count++;
        }
    }

    return count;
}

int words(string text)
{
    int count = 1; // the last space

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

int sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}
