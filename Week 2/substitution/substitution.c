#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// AANSHKVEFXRBAUQZCLWDMIPGAA
bool check_key(string key);
int encrypted_index(char letter);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (check_key(key) == false)
    {
        printf("Key must contain 26 unique characters\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int L = strlen(plaintext);
    char ciphertext[L];

    for (int i = 0; i < L; i++)
    {
        int index = encrypted_index(plaintext[i]);
        if (islower(plaintext[i]))
        {
            ciphertext[i] = key[index] + 32;
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = key[index];
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[L] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool check_key(string key)
{
    int L = strlen(key);
    if (L != 26)
    {
        return false;
    }

    for (int i = 0; i < L; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < L; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = i + 1; j < L; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

int encrypted_index(char letter)
{
    if (isupper(letter))
    {
        letter -= 65;
    }
    else if (islower(letter))
    {
        letter -= 97;
    }
    return letter;
}
