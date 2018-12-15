// Simple implementation of a password cracker in C.
// Cracks DES encrypted alphabetical passwords up to 5 characters in length.

#define _XOPEN_CRYPT

#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyspace[53] =
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'
};

int keyspace_len = 52;

const char salt[3] = {'5', '0', '\0'};

int crack_pass(char hash[], int length)
{

    // First attempt at finding every combination up to 5 chars in length.
    // This turned out to be quite slow because by default it is trying up to 5 char
    // combinations, which can slow down the time it takes to solve shorter combinations.
    for (int i = 0; i < keyspace_len; i++)
    {
        char *c4 = &keyspace[i];
        char *h4 = crypt(&keyspace[i], salt);

        if (strcmp(hash, h4) == 0)
        {
            printf("Password found: %c\n", &keyspace[i]);
            return 0;
        }

        for (int j = 0; j < keyspace_len; j++)
        {
            char *c3 = &keyspace[j];
            char string2[3];
            string2[0] = *c4;
            string2[1] = *c3;
            string2[-1] = '\0';

            char *h3 = crypt(string2, salt);

            if (strcmp(hash, h3) == 0)
            {
                printf("Password found: %s\n", string2);
                return 0;
            }

            for (int k = 0; k < keyspace_len; k++)
            {
                char *c2 = &keyspace[k];
                char string3[4];
                string3[0] = *c4;
                string3[1] = *c3;
                string3[2] = *c2;
                string3[-1] = '\0';

                char *h2 = crypt(string3, salt);

                if (strcmp(hash, h2) == 0)
                {
                    printf("Password found: %s\n", string3);
                    return 0;
                }

                for (int l = 0; l < keyspace_len; l++)
                {
                    char *c1 = &keyspace[l];
                    char string4[5];
                    string4[0] = *c4;
                    string4[1] = *c3;
                    string4[2] = *c2;
                    string4[3] = *c1;
                    string4[-1] = '\0';

                    char *h1 = crypt(string4, salt);

                    if (strcmp(hash, h1) == 0)
                    {
                        printf("Password found: %s\n", string4);
                        return 0;
                    }
                    for (int m = 0; m < keyspace_len; m++)
                    {
                        char *c0 = &keyspace[m];
                        char string5[6];
                        string5[0] = *c4;
                        string5[1] = *c3;
                        string5[2] = *c2;
                        string5[3] = *c1;
                        string5[4] = *c0;
                        string5[-1] = '\0';

                        char *h0 = crypt(string5, salt);

                        if (strcmp(hash, h0) == 0)
                        {
                            printf("Password found: %s\n", string5);
                            return 0;
                        }

                    }
                }
            }
        }
    }
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
    int p_length = 5;
    char hash[h_length];

    strcpy(hash, argv[1]);
    if (crack_pass(hash, p_length) == 1)
    {
        printf("Password could not be found.\n");
        return 1;
    }
}
