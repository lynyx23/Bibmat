#ifndef MATRIXANIMATIONS_H
#define MATRIXANIMATIONS_H

#include "MatrixFunctions.h"

void Animation_Matrix_Cell_Sum(Matrix m, bool &has_ran);
void Window_Matrix_Cell_Sum();
void Animation_Matrix_Cell_Sub(Matrix m, bool &has_ran);
void Window_Matrix_Cell_Sub();
void Animation_Matrix_First_Diag_Sum(Matrix m, bool &has_ran);
void Window_Matrix_First_Diag_Sum();
void Animation_Matrix_Second_Diag_Sum(Matrix m, bool &has_ran);
void Window_Matrix_Second_Diag_Sum();
void Animation_Matrix_Under_First_Diag_Sum(Matrix m, bool &has_ran);
void Window_Matrix_Under_First_Diag_Sum();
void Animation_Matrix_Under_Second_Diag_Sum(Matrix m, bool &has_ran);
void Window_Matrix_Under_Second_Diag_Sum();
void Animation_Matrix_Cell_Mul(Matrix m1, Matrix m2, Matrix &m3, bool &has_ran, int window1, int &window2);
void Window_Matrix_Mul();
void Animation_Matrix_Trans(Matrix m1, Matrix m2, bool &has_ran);
void Window_Matrix_Trans();
void Animation_Matrix_Pow(Matrix m1, Matrix m2, Matrix &m3, bool &has_ran, int window1, int &window2, int iterantions);
void Window_Matrix_Pow();

#endif // MATRIXANIMATIONS_H
