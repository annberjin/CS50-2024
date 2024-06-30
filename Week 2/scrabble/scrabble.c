#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char letters[26];
void config(void);
int get_score(string x);

int main(void)
{
    // CONGIG
    config();

    // Get player 1 and 2 input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int p1 = get_score(player1);
    int p2 = get_score(player2);

    if (p1 > p2)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1 < p2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

void config(void)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
    }
}

int get_score(string x)
{
    int length = strlen(x);
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(x[i]) == letters[j])
            {
                sum += points[j];
            }
        }
    }
    return sum;
}
