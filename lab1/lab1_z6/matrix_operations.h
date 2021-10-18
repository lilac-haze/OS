#ifndef OPERATING_SYSTEM_MATRIX_OPERATIONS_H
#define OPERATING_SYSTEM_MATRIX_OPERATIONS_H





double get(Matrix* matrix, int columnIndex, int rowIndex);
void set(Matrix* matrix, int columnIndex, int rowIndex, double item);
int getColumnSize(Matrix* matrix);
int getRowSize(Matrix* matrix);
void resizeMatrix(Matrix* matrix, int column, int row);
Matrix* sum(Matrix* o1, Matrix* o2);
Matrix* subtraction(Matrix* o1, Matrix* o2);
Matrix* multiplication(Matrix* o1, Matrix* o2);
Matrix* numberMultiplication(Matrix* matrix, double val);

#endif //OPERATING_SYSTEM_MATRIX_OPERATIONS_H
