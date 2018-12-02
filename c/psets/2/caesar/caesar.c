// Simple implementation of a ceasar cipher.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    char ciphertext[length];

    // Loop through plaintext string
    for (int i = 0; i < length; i++)
    {
        // If char is not an alphanumeric character, just copy it
        if (isalpha(plaintext[i]) == false)
        {
            ciphertext[i] = plaintext[i];
        }
        // Check whether shifting it will push it past the ASCII alpha chars and 'wrap' around to start of alphabet if it does
        else if ((isupper(plaintext[i]) && (plaintext[i] + shift) > 'Z') || (islower(plaintext[i]) && (plaintext[i] + shift) > 'z'))
        {
            ciphertext[i] = (plaintext[i] + shift) - 26;
        }
        // Otherwise, just shift it without wrapping around
        else
        {
            ciphertext[i] = plaintext[i] + shift;
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
