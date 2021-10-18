#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "func.h"

int main(void)
{
    int n;
    printf("Enter the number of points\n");
    scanf("%d", &n);
    struct point tmp;
    struct point* arr = (point*)malloc(n * sizeof(point));

    fillArr(arr, n);

    while (n > 1) {

        printArr(arr, n);

        int m1 = find_min(arr, n);
        tmp = arr[m1];
        arr[m1] = arr[n - 1];
        arr[n - 1] = tmp;

        int m2 = find_min_neighbor(arr, n, n - 1);
        arr[m2].weight += arr[n - 1].weight;

        n--;

        arr = (point*)realloc(arr, n * sizeof(point));

        

       // printf("%lu\n", sizeof(arr) / sizeof(point));
    }
    printf("End point: (x=%.2f, y=%.2f, z=%.2f) weight=%.2f\n", arr[0].x, arr[0].y, arr[0].z, arr[0].weight);
    free(arr);

    return EXIT_SUCCESS;
}
