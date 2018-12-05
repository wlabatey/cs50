// Simple implentation of a vigenere cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *argv[])
{
    printf("Usage: %s k\n", argv[0]);
}

int check_arg(char arg[])
{
    for (int i = 0; i < strlen(arg); i++)
    {
        if (isalpha(arg[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void to_lower(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void encrypt_string(string plaintext, char ciphertext[], string key, int length)
{
    to_lower(key);
    int ascii_shift = 0;
    int j = 0;
    int k = 0;
    int k_len = strlen(key);
    // TODO: Fix odd bug that seems to print out garbage values only on some lengths of plaintext.
    // e.g. key = abc, plaintext = helloworld,
    // but not with key = abc, plaintext = hello
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                ascii_shift = 65;
            }
            else
            {
                ascii_shift = 97;
            }

            j = k % k_len;
            int key_val = (key[j] - 97) % 26;
            ciphertext[i] = (((plaintext[i] + key_val) - ascii_shift) % 26) + ascii_shift;
            k++;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length+1] = '\0';
}

int main(int argc, char *argv[])
{
    if (argc != 2 || check_arg(argv[1]) != 0)
    {
        usage(argv);
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    char ciphertext[length];
    encrypt_string(plaintext, ciphertext, key, length);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
