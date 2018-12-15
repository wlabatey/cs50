// Simple implementation of a password cracker in C.
// Cracks DES encrypted alphabetical passwords up to 5 characters in length.

#define _XOPEN_CRYPT

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char keyspace[53] =
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'
};

int keyspace_len = 52;

int crack_pass(char hash[], char salt[])
{
    // Start with 1 char, then 2, 3, 4 and 5.
    // This turned out to be significantly faster than crack0.c
    // because it will solve shorter passwords a lot quicker.

    // Check 1 char combinations
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c0 = &keyspace[i];
        char *h0 = crypt(&keyspace[i], salt);

        if (strcmp(hash, h0) == 0)
        {
            printf("Password found: %c\n", &keyspace[i]);
            return 0;
        }
    }

    // Check 2 char combinations
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c0 = &keyspace[i];
        for (int j = 0; j < keyspace_len; j++)
        {
            char *c1 = &keyspace[j];
            char string2[3];
            string2[0] = *c1;
            string2[1] = *c0;
            string2[-1] = '\0';
            char *h1 = crypt(string2, salt);

            if (strcmp(hash, h1) == 0)
            {
                printf("Password found: %s\n", string2);
                return 0;
            }
        }
    }

    // Check 3 char combinations
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c0 = &keyspace[i];
        for (int j = 0; j < keyspace_len; j++)
        {
            char *c1 = &keyspace[j];
            for (int k = 0; k < keyspace_len; k++)
            {
                char *c2 = &keyspace[k];
                char string3[4];
                string3[0] = *c0;
                string3[1] = *c1;
                string3[2] = *c2;
                string3[-1] = '\0';
                char *h2 = crypt(string3, salt);

                if (strcmp(hash, h2) == 0)
                {
                    printf("Password found: %s\n", string3);
                    return 0;
                }
            }
        }
    }

    // Check 4 char combinations
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c0 = &keyspace[i];
        for (int j = 0; j < keyspace_len; j++)
        {
            char *c1 = &keyspace[j];
            for (int k = 0; k < keyspace_len; k++)
            {
                char *c2 = &keyspace[k];
                for (int l = 0; l < keyspace_len; l++)
                {
                    char *c3 = &keyspace[l];
                    char string4[5];
                    string4[0] = *c0;
                    string4[1] = *c1;
                    string4[2] = *c2;
                    string4[3] = *c3;
                    string4[-1] = '\0';
                    char *h3 = crypt(string4, salt);

                    if (strcmp(hash, h3) == 0)
                    {
                        printf("Password found: %s\n", string4);
                        return 0;
                    }
                }
            }
        }
    }

    // Check 5 char combinations
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c0 = &keyspace[i];
        for (int j = 0; j < keyspace_len; j++)
        {
            char *c1 = &keyspace[j];
            for (int k = 0; k < keyspace_len; k++)
            {
                char *c2 = &keyspace[k];
                for (int l = 0; l < keyspace_len; l++)
                {
                    char *c3 = &keyspace[l];
                    for (int m = 0; m < keyspace_len; m++)
                    {
                        char *c4 = &keyspace[m];
                        char string5[6];
                        string5[0] = *c0;
                        string5[1] = *c1;
                        string5[2] = *c2;
                        string5[3] = *c3;
                        string5[4] = *c4;
                        string5[-1] = '\0';
                        char *h4 = crypt(string5, salt);

                        if (strcmp(hash, h4) == 0)
                        {
                            printf("Password found: %s\n", string5);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // Return 1 if password not found after trying all combinations up to 5 chars.
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s hash\n", argv[0]);
        return 1;
    }

    int h_length = strlen(argv[1]);
    char hash[h_length];
    strcpy(hash, argv[1]);

    // Get the salt dynamically from the first 2 chars of the DES hash, to handle different salts.
    char salt[3];
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';

    if (crack_pass(hash, salt) == 1)
    {
        printf("Password could not be found.\n");
        return 1;
    }
}
