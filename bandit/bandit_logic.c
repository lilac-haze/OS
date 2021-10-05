#include <stdio.h>
#include <stdlib.h>

#include "bandit_input.h"
#include "bandit_output.h"




int *generateNumbers(int len)
{
    int *arr = (int *)malloc(sizeof(int) * len);
    int i;
    for (i = 0; i < len; i++)
    {
        arr[i] = (rand() % 12) + 1;
    }

    return arr;
}


void printArray(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isAllNumbersEqualsNumber(int* array, int length, int number) {
    int index;

    for (index = 0; index < length; index++) {
        if (array[index] != number) {
            return 0;
        }
    }
    
    return 1;
}

int isAllNumbersTheSame(int* array, int length) {
    int index;

    for (index = 1; index < length; index++) {
        if (array[index] != array[index - 1]) {
            return 0;
        }
    }
    
    return 1;
}

int isTwoThirdsNumbersTheSame(int* array, int length) {
    int currentEqualsNumbersCounter = 0;
    int maxNumberEquals = 0;
    int needableNumberEquals = length * 2.0 / 3.0;

    int i;
    for (i = 0; i < length; i++) {

        int j;
        for (j = i; j < length; j++) {
            if (array[i] == array[j]) {
                currentEqualsNumbersCounter++;
            }
        }

        if (maxNumberEquals < currentEqualsNumbersCounter) {
            maxNumberEquals = currentEqualsNumbersCounter;
        }

        currentEqualsNumbersCounter = 0;
    }
    
    return maxNumberEquals >= needableNumberEquals ? 1 : 0;
}

int isArrayContainsNumber(int* array, int length, int number) {
    int index;

    for (index = 0; index < length; index++) {
        if (array[index] == number) {
            return 1;
        }
    }
    
    return 0;
}
