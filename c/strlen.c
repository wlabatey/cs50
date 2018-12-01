// Basic implentation of the strlen function

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for name.
    string s = get_string("Name: ");
    int n = 0;

    // Loop through string, checking for null byte and incrementing 'n'.
    while (s[n] != '\0')
    {
        n++;
    }

    printf("%i\n", n);
}
