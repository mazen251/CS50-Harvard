#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkinput(string input, int size);
int checksize(string input);

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int sizeplayer1 = checksize(player1);
    int sizeplayer2 = checksize(player2);

    int player1score = checkinput(player1, sizeplayer1);
    int player2score = checkinput(player2, sizeplayer2);

    // printf("This is the size of the first string: %i\n", sizeplayer1);
    // printf("This is the size of the second string: %i\n", sizeplayer2);

    // printf("Score of player 1: %i\n", player1score);
    // printf("Score of player 2: %i\n", player2score);

    if (player1score > player2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1score < player2score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int checkinput(string input, int size)
{
    int score = 0;

    for (int i = 0; i < size; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z') // checks for the lower case alphabet and maps them
                                                // to their corresponding value in the list POINTS
        {
            score += POINTS[input[i] - 'a'];
        }
        else if (input[i] >= 'A' &&
                 input[i] <= 'Z') // checks for the upper case alphabet and maps them to their
                                  // corresponding value in the list POINTS
        {
            score += POINTS[input[i] - 'A'];
        }
        // Anything else not being a lowe case or upper case char of the alphabet is neglected, also
        // could have easily replaced what' inside of the conditions with toupper(input[i]) or
        // tolower(input[i])
    }

    return score;
}

int checksize(string input)
{
    int n = 0;

    while (input[n] != '\0')
    {
        n++;
    }

    return n;
}
