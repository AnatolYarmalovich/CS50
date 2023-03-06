#include <stdio.h>
#include <string.h>
#include "../../C/cs50lib/cs50.h"
#include <ctype.h>

int ASCIIOffset = 65;

bool isArgumentsValid(int argc, string argv[]);
bool isContainDuplicates(string text);
string handle_user_input();
char rotate(char symbol, int position);
void encode(string text, string key);


int main(int argc, string argv[])
{

    if (isArgumentsValid(argc, argv))
    {
        string text = handle_user_input();
        encode(text, argv[1]);
    }
    else
    {
        return 1;
    }
    return 0;
}

string handle_user_input()
{
    string text;
    text = get_string("plaintext: ");
    return text;
}

bool isArgumentsValid(int argc, string argv[])
{
    bool isValid = false;

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return isValid;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return isValid;
    }

    if (isContainDuplicates(argv[1]))
    {
        printf("Usage: ./substitution key");
        return isValid;
    }

    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        if (isalpha(argv[1][i]))
        {
            isValid = true;
        }
        else
        {
            isValid = false;
            break;
        }
    }

    if (!isValid)
    {
        printf("Usage: ./substitution key");
    }
    return  isValid;
}

void encode(string text, string key)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); ++i)
    {
        char coded;
        if (isalpha(text[i]))
        {
            int characterNumber = (int)toupper(text[i]);
            int index = characterNumber - ASCIIOffset;
            coded = key[index];
            if (islower(text[i]))
            {
                coded = tolower(coded);
            }
            else
            {
                coded = toupper(coded);
            }
        }
        else
        {
            coded = text[i];
        }
        printf("%c", coded);
    }
    printf("\n");
}

bool isContainDuplicates(string text)
{
    for (int i = 0; i < strlen(text); ++i)
    {
        for (int j = i + 1; j < strlen(text); ++j)
        {

            if (text[i] == text[j])
            {
                return true;
            }
        }
    }
    return false;
}