#include "../../C/cs50lib/cs50.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void printBulb(int bit);
string getUserMessage(void);
void printMsgAsBulb(string message);

int main(void)
{
    string message = getUserMessage();
    printMsgAsBulb(message);
}

void printMsgAsBulb(string message)
{
    for (int i = 0; i < strlen(message); ++i)
    {
        int bulbs[BITS_IN_BYTE];
        int currentNumber = message[i];

        for (int j = 0; j < BITS_IN_BYTE; ++j)
        {

            int currentBinary = pow(2, BITS_IN_BYTE - j - 1);

            if (currentNumber >= currentBinary)
            {
                bulbs[j] = 1;
                currentNumber -= currentBinary;
            }
            else
            {
                bulbs[j] = 0;
            }
        }

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            printBulb(bulbs[j]);
        }

        printf("\n");
    }
}

string getUserMessage(void)
{
    string message;
    message = get_string("Message: ");
    return message;
}

void printBulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
