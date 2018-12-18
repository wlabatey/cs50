// A Program to validate credit card numbers using Luhn's algorithm.

#define BUF_MAX 20

#include <cs50.h>
#include <stdio.h>
#include <string.h>

struct digits {
    int first;
    int both;
};

struct digits get_digits(long long *card_number)
{
    struct digits digits = {0};
    char digits_buffer[3];

    snprintf(digits_buffer, 3, "%llu", *card_number);

    digits.first = digits_buffer[0] - '0'; // Convert ascii char to decimal. Ascii char '0' is 48 in decimal.
    digits.both = atoi(digits_buffer);

    return digits;
}

void validate_card_number(long long *card_number, char *card_type)
{
    char card_buffer[BUF_MAX];
    sprintf(card_buffer, "%llu", *card_number);

    int total_odd = 0;
    int total_even = 0;

    for (int i = 0; i < strlen(card_buffer); i++)
    {
        if (card_buffer[i] == '\0')
        {
            break;
        }

        if ((strlen(card_buffer) % 2 != 0 && i % 2 == 0) || strlen(card_buffer) % 2 == 0 && i % 2 != 0)
        {
            total_even += ((int) card_buffer[i] - '0');
        }
        else
        {
            int digit = ((int) card_buffer[i] - '0') * 2;
            if (digit > 9)
            {
                char digit_buffer[3];
                sprintf(digit_buffer, "%d", digit);

                for (int i = 0; i < strlen(digit_buffer); i++)
                {
                    if (digit_buffer[i] == '\0')
                    {
                        break;
                    }
                    total_odd += ((int) digit_buffer[i] - '0');
                }
            }
            else
            {
                total_odd += digit;
            }
        }
    }

    if ((total_odd + total_even) % 10 != 0)
    {
        strcpy(card_type, "INVALID\0");
    }
}

int main(void)
{
    long long card_number = get_long_long("Number: ");
    char card_type[BUF_MAX];
    struct digits card_digits = get_digits(&card_number);

    if (card_digits.first == 4)
    {
        strcpy(card_type, "VISA\0");
    }
    else
    {
        switch(card_digits.both)
        {
            case 34:
            case 37: strcpy(card_type, "AMEX\0"); break;

            case 51:
            case 52:
            case 53:
            case 54:
            case 55: strcpy(card_type, "MASTERCARD\0"); break;

            default: strcpy(card_type, "INVALID\0"); break;
        }
    }

    if (strcmp(card_type, "INVALID") == 0)
    {
        printf("%s\n", card_type);
        return 0;
    }

    validate_card_number(&card_number, card_type);
    printf("%s\n", card_type);

    return 0;
}
