#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#include "matrix.h"
#include "matrix_operations.h"


double get(Matrix* matrix, int columnIndex, int rowIndex){
    return matrix->data[rowIndex][columnIndex];
}

void set(Matrix* matrix, int columnIndex, int rowIndex, double item){
    matrix->data[rowIndex][columnIndex] = item;
}

int getColumnSize(Matrix* matrix){
    return matrix->column;
}

int getRowSize(Matrix* matrix){
    return matrix->row;
}

void resizeMatrix(Matrix* matrix, int column, int row){
    double** newMatrix =(double **) malloc(sizeof(double*) * row);
   

    for (int i = 0; i < row; i++){
        newMatrix[i] = (double *)calloc(sizeof(double) ,column);
    }

    for (int i = 0; i < row && i < matrix->row; i++){
        for (int j = 0; j < column && j < matrix->column; j++){
            newMatrix[i][j] = matrix->data[i][j];
        }        
    }

    for (size_t i = 0; i < matrix->row; i++){
        free(matrix->data[i]);
    }

    free(matrix->data);
    
    matrix->row = row;
    matrix->column = column;
    matrix->data = newMatrix;
}


Matrix* sum(Matrix* o1, Matrix* o2){

    if (o1->row == o2->row && o1->column == o2->column){
        
        Matrix* sum = newMatrix(o1->column,o1->row);

        for (int i = 0 ; i < sum->row; i++){
            for (int j = 0; j < sum->column; j++) {
                sum->data[i][j] = o1->data[i][j] + o2->data[i][j];
            }
        }
        return sum;
    }
    else{
        return NULL;
    }
}

Matrix* subtraction(Matrix* o1, Matrix* o2){

    if (o1->row == o2->row && o1->column == o2->column){
        
        Matrix* subtraction = newMatrix(o1->column,o1->row);

        for (int i = 0 ; i < subtraction->row; i++){
            for (int j = 0; j < subtraction->column; j++) {
                subtraction->data[i][j] = o1->data[i][j] - o2->data[i][j];
            }
        }
        return subtraction;
    }
    else{
        return NULL;
    }
}

Matrix* multiplication(Matrix* o1, Matrix* o2){

    if (o1->column == o2->row){
        Matrix* multiplication = newMatrix(o2->column,o1->row);

        for (int i = 0; i < multiplication->row; i++) {
            for (int j = 0; j < multiplication->column; j++) {
                multiplication->data[i][j] = 0;
                for (int k = 0; k < o1->column ; k++) { 
                    multiplication->data[i][j] = multiplication->data[i][j] 
                        + o1->data[i][k] * o2->data[k][j];
                }
            }
        }
        return multiplication;
    }
    else{
        return NULL;
    }
}

Matrix* numberMultiplication(Matrix* matrix, double val){
    Matrix* multiplicatioByNumber = newMatrix(matrix->column, matrix->row);

    for (int i = 0; i < matrix->row; i++){
        for (int j = 0; j < matrix->column; j++){
            multiplicatioByNumber->data[i][j] = matrix->data[i][j] * val;
        }
    }
    return multiplicatioByNumber;
}
