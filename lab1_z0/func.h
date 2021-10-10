#ifndef _FUNC_H_
#define _FUNC_H_

typedef struct point {
    float x, y, z, weight;
} point, *ppoint;


float Distance(struct point p, struct point q);
void printArr(point* arr, int n);
void fillArr(point* str,int n);
int find_min(point* str,int n);
int find_min_neighbor(point* arr,int n,int j);

#endif
