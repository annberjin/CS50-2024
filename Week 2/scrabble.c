#include <cs50.h>
#include <stdio.h>
#include <string.h>

int points[26];
char letters[26];
void config(void);
bool winner(string x, string y);

int main(void)
{
    // CONGIG
    config();


    // Get player 1 and two input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    winner(player1, player2);
}

void config(void)
{
    int i;
    for (i=0; i<26; i++)
    {
        points[i] = i + 1;
        letters[i] = 'a' + i;
    }
}

bool winner(string x, string y)
{
    int word1 = strlen(x);
    int word2 = strlen(y);
    int sum = 0;
    for (int i=0; i < word1; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (x[i] == letters[j])
            {
                printf("%c", x[i]); //IT WORKS
            }
        }
    }


    return true;
}
