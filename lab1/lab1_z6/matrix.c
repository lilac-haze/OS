#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#include "matrix.h"
#include "matrix_operations.h"

Matrix* newMatrix(int column, int row){
    Matrix* matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->column = column;
    matrix->data = (double **)malloc(sizeof(double*) * row);
   

    for (int i = 0; i < row; i++){
        matrix->data[i] = (double *)malloc(sizeof(double) * column);
    }
    return matrix;
}

void printMatrix(Matrix* matrix){
    for (int i = 0; i < matrix->row; i++){
        for (int j = 0; j < matrix->column; j++){
            printf("%0.2lf ",matrix->data[i][j]);
        }
        printf("\n");
    }
}


void randomMatrix(Matrix* matrix){
   for (int i = 0; i < matrix->row; i++){
        for (int j = 0; j < matrix->column; j++){
        	
       matrix->data[i][j]=round(((double) rand() / RAND_MAX) * (9.0 - 1.5) + 1.5);  
        
        }
    }
}

void clearMatrix(Matrix* matrix){
    for (size_t i = 0; i < matrix->row; i++){
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void saveMatrix(Matrix* matrix,char* path){
    FILE* file = fopen(path, "wb");
    
    fwrite(&matrix->row,sizeof(int),1,file);
    fwrite(&matrix->column,sizeof(int),1,file);

    for (int i = 0; i < matrix->row; i++){
        fwrite(matrix->data[i], sizeof(double),matrix->column, file);
    }
    fclose(file);
}

Matrix* readMatrix(char* path){
    FILE* file = fopen(path, "rb");

    int column = 0;
    int row = 0;
    fread(&column,sizeof(int),1,file);
    fread(&row,sizeof(int),1,file);
    printf("\n%d %d\n",column,row);

    Matrix* matrix = newMatrix(column,row);


    for (int i = 0; i < matrix->row; i++){
        fread(matrix->data[i], sizeof(double), matrix->column, file);
    }
    fclose(file);
    return matrix;
}

