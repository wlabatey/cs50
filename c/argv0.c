// Take command line arguments and print the first.

#include <cs50.h>
#include <stdio.h>

// argc is the count of arguments, argv is an array of the argument strings.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
