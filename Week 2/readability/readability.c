#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    // Compute the Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int length = strlen(text);
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int length = strlen(text);
    int counter = 1;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int length = strlen(text);
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            counter++;
        }
    }
    return counter;
}
