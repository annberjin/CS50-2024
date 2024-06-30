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
    int l = strlen(plaintext);
    char ciphertext[l];

    // For each character in the plaintext:
    for (int i = 0; i < l; i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
    }
    ciphertext[l] = '\0';

    printf("ciphertext: %s\n", ciphertext);
}

char rotate(char letter, int key)
{
    //char new = letter + key % 26; // Something is wrong here
    char new;
    if isupper(letter)
    {
        new = (((letter - 65) + key) % 26) + 65; // 'A'
    }
    else if islower(letter)
    {
        new = (((letter - 97) + key) % 26) + 97; // 'A'
    }
    else
    {
        return letter;
    }
    return new;
}
