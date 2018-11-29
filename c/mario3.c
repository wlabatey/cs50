// Prompt user for amount of times to loop, then print question marks.

#include <string.h>
#include <stdio.h>
#include <cs50.h>

// Define a maximum string length
#define STRMAX 100

int main(void)
{
    // Prompt user for a number.
    int n = 1;

    // Set a default prompt message
    char msg[STRMAX] = "How many times shall we loop? ";
    do
    {
        // Change prompt message if user specifies a negative integer.
        if (n <= 0)
        {
            strncpy(msg, "Please provide a positive number: ", STRMAX);
        }
        n = get_int(msg);
    }
    while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}
