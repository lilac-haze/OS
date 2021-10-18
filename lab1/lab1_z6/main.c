#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#include "matrix.h"
#include "matrix_operations.h"

int main(int argc, char const *argv[]){
    
    //New matrix
    printf("What is the size of the matrix? ");
	int r, c;
	scanf("%d %d", &r, &c);
    Matrix* matrix1 = newMatrix(r, c);
    randomMatrix(matrix1);
    
    //Save matrix
    saveMatrix(matrix1,"matrix.data");

    //Read saved matrix
    Matrix* savedMatrix = readMatrix("matrix.data");

    //Print saved matrix
    printf("\n");
    printMatrix(savedMatrix);
    printf("\n");
    
    //New matrix 2
    printf("New matrix with same size\n");
    Matrix* matrix2 = newMatrix(r,c);
    randomMatrix(matrix2);

    //Print matrix 1 and 2
    //printMatrix(matrix1);
    printMatrix(matrix2);
printf("\n");
    printf("Sum: \n");
    Matrix* sumMatrix = sum(matrix1,matrix2);
    printMatrix(sumMatrix);
printf("\n");
    printf("Subtraction : \n");
    Matrix* subtractionMatrix = subtraction(matrix1,matrix2);
    printMatrix(subtractionMatrix);
printf("\n");
    //Set and get matrix item
    printf("Set matrix[0][0] as 22 \n");
    set(matrix1,0,0,22);
    printMatrix(matrix1);
    printf("Get matrix[0][0]: \n");
    printf("get: %0.2lf\n\n", get(matrix1,0,0));

    //Resized matrix
    printf("Resize matrixs (rows 2, columns 3):");
    resizeMatrix(matrix1,3,2);
    resizeMatrix(matrix2,2,3);

    //Input Matrix
    printf("\n");
    randomMatrix(matrix1);
    printf("\n");
    randomMatrix(matrix2);

    printf("\n");
    printMatrix(matrix1);
    printf("\n");
    printMatrix(matrix2);

 printf("\n");
printf("Multiplication: \n");
    //Multiplication matrix
    Matrix* multiplMatrix = multiplication(matrix1,matrix2);

    printf("\n");
    printMatrix(multiplMatrix);

    //Multiplication to num;
     printf("\n");
printf("Multiplication by 6: \n");
    Matrix* multiplMatrixN = numberMultiplication(matrix1, 6);
    printf("\n");
    printMatrix(multiplMatrixN);

printf("Clear matrixs \n");
    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(sumMatrix);
    clearMatrix(subtractionMatrix);
    clearMatrix(multiplMatrix);
    clearMatrix(multiplMatrixN);
    return 0;
    
}
