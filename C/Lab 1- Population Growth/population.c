#include <stdio.h>
#include "../cs50lib/cs50.h"

int promptStartSize(void);
int promptEndSizeFor(int startSize);
int calculateYearsWith(int startSize, int endSize);
void printYears(int years);

int main(void)
{
    // TODO: Prompt for start size
    int startSize = promptStartSize();

    // TODO: Prompt for end size
    int endSize = promptEndSizeFor(startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = calculateYearsWith(startSize, endSize);

    // TODO: Print number of years
    printYears(years);
}

int promptStartSize(void)
{
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);
    return startSize;
}

int promptEndSizeFor(int startSize)
{
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);
    return endSize;
}

int calculateYearsWith(int startSize, int endSize)
{
    int year = 0;
    int population = startSize;

    do
    {
        float born = (float)population / 3;
        float died = (float)population / 4;
        population = population + (int)born - (int)died;
        year++;
    }
    while (population < endSize);

    return year;
}

void printYears(int years)
{
    printf("Years: %i\n", years);
}