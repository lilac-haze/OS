#ifndef OPERATING_SYSTEM_MATRIX_H
#define OPERATING_SYSTEM_MATRIX_H

typedef struct matrix_x Matrix;

typedef struct matrix_x{
    int column;
    int row;
    double** data;
}Matrix;

Matrix* newMatrix(int column, int row);
void printMatrix(Matrix* matrix);
void randomMatrix(Matrix* matrix);
void clearMatrix(Matrix* matrix);
void saveMatrix(Matrix* matrix,char* path);
Matrix* readMatrix(char* path);

#endif //OPERATING_SYSTEM_MATRIX_H
