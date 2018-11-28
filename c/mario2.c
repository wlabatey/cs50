// Prompt user for amount of times to loop, then print question marks.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Max number of loop iterations.
    int n = get_int("How many times shall we loop? ");

    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}
