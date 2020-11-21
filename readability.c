#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_letters(string l);
int count_words(string w);
int count_sentences(string w);
int find_index(string t);

//if over grade 16 just prints 16+
//if under grade 1 just prints Before Grade 1
int main(void)
{
    string text = get_string("Text: ");
    if (find_index(text) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (find_index(text) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", find_index(text));
    }
}

//counts all letters excluding punctuation
int count_letters(string l)
{
    int counter = 0;
    for (int i = 0; l[i] != '\0'; i++)
    {
        if (((int) l[i] >= 65 && (int) l[i] <= 90) || ((int) l[i] >= 97 && (int) l[i] <= 122))
        {
            counter++;
        }
    }
    return counter;
}

//counts number of spaces and adds 1 = words
int count_words(string w)
{
    int counter = 0;
    for (int i = 0; w[i] != '\0'; i++)
    {
        if ((int) w[i] == 32)
        {
            counter++;
        }
    }
    return counter + 1;
}

//count number of sentences.
//This is faulty given that Mr. and Mrs. counts as 2 sentences there
int count_sentences(string w)
{
    int counter = 0;
    for (int i = 0; w[i] != '\0'; i++)
    {
        if ((int) w[i] == 33 || (int) w[i] == 46 || (int) w[i] == 63)
        {
            counter++;
        }
    }
    return counter;
}

// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text
//finds index using Coleman-Liau index
int find_index(string t)
{
    float L = (float) count_letters(t) * 100 / (float) count_words(t);
    float S = (float) count_sentences(t) * 100 / (float) count_words(t);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    return round(index);
}