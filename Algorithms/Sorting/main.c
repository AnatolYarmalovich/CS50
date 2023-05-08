#include <stdio.h>

void selectionSort(int array[], int lenght);
void printArray(int arr[], int size);
void bubbleSort(int array[], int lenght);

int main() {
    int forSelectionSort[] = {7, 2, 5};
    int forBubbleSort[] = {3, 4, 1, 2};
    bubbleSort(forBubbleSort, 4);
    printArray(forBubbleSort, 4);
    selectionSort(forSelectionSort, 3);
    printArray(forSelectionSort, 3);
    return 0;
}

void selectionSort(int array[], int lenght)
{
    int minIndex;
    for (int i = 0; i < lenght - 1; ++i)
    {
        minIndex = i;

        for (int j = i + 1; j < lenght; ++j)
        {
            if (array[minIndex] > array[j])
            {
                minIndex = j;
            }

        }

        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void bubbleSort(int array[], int lenght)
{
    for (int i = 0; i < lenght; ++i) {
        for (int j = 1; j < lenght - i; ++j) {
            if (array[j] < array[j - 1])
            {
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}