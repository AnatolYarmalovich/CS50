#include <stdio.h>
#include "../../C/cs50lib/cs50.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int const LETTERS_COUNT_ALPHABET = 25;

bool is_argument_valid(int argc, char *argv[]);
string handle_user_input();
void encode(int key, string text);
char rotate(char symbol, int position);


int main(int argc, char *argv[])
{
    if (is_argument_valid(argc, argv))
    {
        string userInput = handle_user_input();
        int key = atoi(argv[1]);
        encode(key, userInput);
    }
    else
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    return 0;
}

bool is_argument_valid(int argc, char *argv[])
{
    bool isValid = false;

    if (argc != 2)
    {
        return false;
    }

    for (int i = 0; i < strlen(argv[1]); ++i) {
        if (isdigit(argv[1][i]))
        {
            isValid = true;
        }
        else
        {
            isValid = false;
            break;
        }
    }
    return  isValid;
}

string handle_user_input()
{
    string text;
    text = get_string("plaintext: ");
    return text;
}

char rotate(char symbol, int position)
{
    int charNumber = (int)symbol;

    if (!isalpha(symbol)) {
        return symbol;
    }

    while(position != 0)
    {
        if ((charNumber + 1) == 91 || (charNumber + 1) == 123)
        {
            charNumber -= LETTERS_COUNT_ALPHABET;
        }
        else
        {
            charNumber++;
        }
        position--;
    }

    return (char)charNumber;
}

void encode(int key, string text)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); ++i)
    {
        int charNumber = (int)text[i];

        char coded = rotate(text[i], key);
        printf("%c", coded);
    }
    printf("\n");
}