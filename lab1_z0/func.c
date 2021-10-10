#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "func.h"

void printArr(struct point* arr, int n)
{
    printf("\n------------------------------\n");
    for (int i = 0; i < n; ++i) {
        printf("Point %d(x=%.2f, y=%.2f, z=%.2f) weight=%.2f\n", i, arr[i].x, arr[i].y, arr[i].z, arr[i].weight);
    }
    printf("\n------------------------------\n");
}

void fillArr(point* str, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        str[i].x = rand() % 100;
        str[i].y = rand() % 100;
        str[i].z = rand() % 100;
        str[i].weight = rand() % 100;
    }
}

int find_min(point* str, int n)
{
    float min_m = str[0].weight;
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (str[ind].weight < min_m) {
            min_m = str[ind].weight;
            ind = i;
        }
    }
    return ind;
}

float Distance(struct point p, struct point q)
{
float res = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) + (p.z - q.z));
    return res;
}

int find_min_neighbor(point* arr, int n, int j)
{

    float min_r = 0;
    int ind = 0;
    if (ind == j)
        ind++;
    min_r = Distance(arr[j], arr[ind]);
    for (int i = 0; i < n; i++) {
        if (i != j && min_r < Distance(arr[j], arr[i])) {
            min_r = Distance(arr[j], arr[i]);
            ind = i;
        }
    }
    return ind;
}
