#include <stdio.h>
#include "../../C/cs50lib/cs50.h"
#include <ctype.h>
#include <string.h>
#include <math.h>

string user_text_prompt(void);
void calculate_grade_points(string text);
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main() {
    string text = user_text_prompt();
    calculate_grade_points(text);
}

string user_text_prompt(void)
{
    string text;
    text = get_string("Text: ");
    return text;
}

void calculate_grade_points(string text)
{
    float L, S;

    float sentences = (float)count_sentences(text);
    float words = (float)count_words(text);
    float letters = (float)count_letters(text);

    L = (letters / words) * 100.0;
    S = (sentences / words) * 100.0;

    float result = (0.0588 * L) - (0.296 * S) - 15.8;

    int index = (int) roundf(result);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); ++i)
    {
        bool sentencesCondition = text[i] == '.' || text[i] == '?' || text[i] == '!';

        if (sentencesCondition)
        {
            sentences += 1;
        }
    }
    return sentences;
}

int count_words(string text)
{
    int word = 0;

    for (int i = 0; i < strlen(text); ++i)
    {

        if (isspace(text[i]))
        {
            word += 1;
        }
    }

    //Add one more because of end
    if (word > 0)
    {
        word += 1;
    }

    return  word;
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); ++i)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}