#include <stdio.h>
#import "../cs50lib/cs50.h"

void printPyramid(int height);

int promptHeight(void);

int main(void)
{
    int height = promptHeight();
    printPyramid(height);
}

int promptHeight(void) {
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    return height;
}

void printPyramid(int height) {

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if ((height - 1 - i) <= j)
            {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

