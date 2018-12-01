// Prompt user for input, then loop through char array and print each char alongside its ascii code.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user for a string (char array)
    string s = get_string("Name: ");

    // Loop through string
    for (int i = 0; i < strlen(s); i++)
    {
        // Print each char alongside the char typecasted to an int
        printf("%c %i\n", s[i], (int) s[i]);
    }
}
