#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc <= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // For each character in the plaintext:

    // Rotate the character if it's a letter
}

char rotate(char letter, int key)
{
    return ' ';
}
