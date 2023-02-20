#include <stdio.h>
#include "../cs50lib/cs50.h"
#include <math.h>

void identifyCardWith(long number);
int getFirstTwoDigitsFrom(long number);
int getCountOfDigitFrom(long number);
bool isCardValid(long number);
bool isInRange(int lowerLimit, int upperLimit, int no);
long getCardNumber(void);

int main(void) {
    long cardNumber = getCardNumber();
    identifyCardWith(cardNumber);
}


void identifyCardWith(long number)
{

    bool validCard = isCardValid(number);

    if (!validCard)
    {
        printf("INVALID\n");
        return;
    }

    int firstTwoDigits = getFirstTwoDigitsFrom(number);
    if (isInRange(51,55,firstTwoDigits) && getCountOfDigitFrom(number) == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (isInRange(40, 49, firstTwoDigits) && (getCountOfDigitFrom(number) == 16 || getCountOfDigitFrom(number) == 13))
    {
        printf("VISA\n");
    }
    else if ((firstTwoDigits == 37 || firstTwoDigits == 39) && getCountOfDigitFrom(number) == 15)
    {
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }
}

int getFirstTwoDigitsFrom(long number)
{
    long num = number;

    while (num >= 100)
    {
        num /= 10;
    }

    return (int)num;
}

int getCountOfDigitFrom(long number)
{
    if(number == 0)
    {
        return 1;
    }
    else
    {
        return (int)(log10(number) + 1);
    }
}

bool isCardValid(long number) {
    int sum1 = 0;
    int sum2 = 0;
    long x = number;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;

    return total % 10 == 0;
}

bool isInRange(int lowerLimit, int upperLimit, int no)
{
    return (lowerLimit <= no && no <= upperLimit);
}

long getCardNumber(void)
{
    long cardNumber;

    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber <= 0);

    return  cardNumber;
}