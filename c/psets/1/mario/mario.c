// A program that prints out a double half-pyramid of a specified height.

#define MIN_HEIGHT 0
#define MAX_HEIGHT 23

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int height = 0;
    do
    {
        if (height < MIN_HEIGHT || height > MAX_HEIGHT)
        {
            height = get_int("Please enter an integer between %i and %i\nHeight: ", MIN_HEIGHT, MAX_HEIGHT);
        }
        else
        {
            height = get_int("Height: ");
        }
    } while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    for (int i = 1; i <= height; i++)
    {
        int shift = (height - i);

        for (int j = 0; j < shift; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf(" ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
