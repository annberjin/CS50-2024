#include <cs50.h>
#include <stdio.h>
#include <string.h>

int points[26];
char letters[26];
void config(void);

int main(void)
{
    // CONGIG
    config();
    printf("%i\n", points[25]);
    printf("%c\n", letters[12]);

    // Get player 1 and two input
    //string player1 = get_string("Player 1: ");
    //string player2 = get_string("Player 2: ");
}

void config(void)
{
    int i;
    for (i=0; i<26; i++)
    {
        points[i] = i + 1;
        letters[i] = 'a' + 1;
    }
}

bool winner(string x, string y)
{
    int word1 = strlen(x);
    int word2 = strlen(y);
    return true;

}
