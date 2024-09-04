#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Enter a credit card number: ");
    long credittemp = credit;
    int tempfortemp;
    int digit;
    int counter = 1;
    int sum = 0;
    int sum2 = 0;
    int temp;

    while (credit > 0)
    {
        digit = credit % 10;
        credit /= 10;
        if (counter % 2 == 0)
        {
            digit *= 2;
            // printf("Digit %i: %i\n", counter, digit);
            if (digit > 9)
            {
                temp = digit; // b3ml kda 3lshan lma ageb tany digit lw 3mlt digit /= 10 fna kda
                              // b3ml l awl digit fl 2 digit number f dyman < 10
                digit %= 10;  // gets the first digit
                sum += digit;
                temp /= 10; // gets the second digit
                sum += temp;
            }
            else
            {
                sum += digit;
            }
        }
        else
        {
            sum2 += digit;
        }
        counter++;
    }

    // printf("Digit: %li\n",credittemp);

    if ((sum + sum2) % 10 == 0)
    {
        while (credittemp > 100)
        {
            credittemp /= 10;
        }

        int length = counter - 1;

        if ((credittemp == 34 || credittemp == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if ((credittemp >= 51 && credittemp <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((credittemp / 10 == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

        // printf("the first two digits %li\n", credittemp);
    }
    else
    {
        printf("INVALID\n");
    }

    // printf("the total even numebrs sum is : %i\n", sum);
    // printf("the total odd numbers sum is : %i\n", sum2);
    // printf("the total even and odd sums is : %i\n", sum + sum2);
}
