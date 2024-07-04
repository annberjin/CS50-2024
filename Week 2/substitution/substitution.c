#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char key[26];
void add_key(string x);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    add_key(argv[1]);
    // printf("%c\n", key[2]);

    string plaintext = get_string("Plaintext: ");
    int L = strlen(plaintext);
    char ciphertext[L];
}

void add_key(string x)
{
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(x[i]);
    }
}
