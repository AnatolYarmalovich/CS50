#include <stdio.h>
#include "../cs50lib/cs50.h"

int getHeightPrompt(void);
void buildWall(int height);

int main(void)
{
    //Create getter for height
    int height = getHeightPrompt();

    //Create task handler
    buildWall(height);
}

int getHeightPrompt(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return  height;
}

void buildWall(int height)
{

    for (int row = 0; row < height; ++row)
    {
        for (int space = height - row - 1; space > 0; --space)
        {
            printf(" ");
        }

        for (int leftPile = height - row - 1; leftPile < height; ++leftPile)
        {
            printf("#");
        }

        printf("  ");

        for (int rightPile = 0; rightPile < row + 1; ++rightPile)
        {
            printf("#");
        }
        printf("\n");
    }
}