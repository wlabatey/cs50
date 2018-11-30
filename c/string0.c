// Prompt user for input, then loop through string (char array) and print each char.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user input
    string s = get_string("input:  ");

    // Print output without newline
    printf("output:  ");

    // Loop through user input and print each char.
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
