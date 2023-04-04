#include <stdio.h>

// declare constant
#define ArrayA2D_ROW_Size 3
#define ArrayA2D_COLUMN_Size 2
#define ArrayB2D_ROW_Size 2
#define ArrayB2D_COLUMN_Size 3

// function prototype
void storeAarray2D(int _ArrayA2D_ROW_Size, int _ArrayA2D_COLUMN_Size, int _iAarray2D[_ArrayA2D_ROW_Size][_ArrayA2D_COLUMN_Size]); // store user's input in Aarray2Darray
void storeBarray2D(int _ArrayB2D_ROW_Size, int _ArrayB2D_COLUMN_Size, int _iBarray2D[_ArrayB2D_ROW_Size][_ArrayB2D_COLUMN_Size]); // store user's input in Barray2Darray
void multiply2DArray(int _ArrayA2D_ROW_Size, int _ArrayA2D_COLUMN_Size, int _ArrayB2D_ROW_Size, int _ArrayB2D_COLUMN_Size, int _iAarray2D[_ArrayA2D_ROW_Size][_ArrayA2D_COLUMN_Size], int _iBarray2D[_ArrayB2D_ROW_Size][_ArrayB2D_COLUMN_Size], int _iMultiArray2D[_ArrayA2D_ROW_Size][_ArrayB2D_COLUMN_Size]); // calculate multiplication
void printArray2D(int _row_Size, int _column_Size, int _Array[_row_Size][_column_Size]); // print out the result

// start main
int main(void)
{
    int iAarray2D[ArrayA2D_ROW_Size][ArrayA2D_COLUMN_Size] = {0}; // def and initialize Aarray2D
    int iBarray2D[ArrayB2D_ROW_Size][ArrayB2D_COLUMN_Size] = {0}; // def and initialize Barray2D
    int iMultiArray2D[ArrayA2D_ROW_Size][ArrayB2D_COLUMN_Size] = {0}; // def and initialize multiArray2D

    storeAarray2D(ArrayA2D_ROW_Size, ArrayA2D_COLUMN_Size, iAarray2D); // store user's input in array
    storeBarray2D(ArrayB2D_ROW_Size, ArrayB2D_COLUMN_Size, iBarray2D); // store user's input in array

    multiply2DArray(ArrayA2D_ROW_Size, ArrayA2D_COLUMN_Size, ArrayB2D_ROW_Size, ArrayB2D_COLUMN_Size, iAarray2D, iBarray2D, iMultiArray2D); // calculate

    printf("Array_A: \n");
    printArray2D(ArrayA2D_ROW_Size, ArrayA2D_COLUMN_Size, iAarray2D); // print Array_A
    
    printf("Array_B: \n");
    printArray2D(ArrayB2D_ROW_Size, ArrayB2D_COLUMN_Size, iBarray2D); // print Array_B
    
    printf("The multiply array: \n");
    printArray2D(ArrayA2D_ROW_Size, ArrayB2D_COLUMN_Size, iMultiArray2D); // print new Aarray2D
} // end main

// def function
void storeAarray2D(int _ArrayA2D_ROW_Size, int _ArrayA2D_COLUMN_Size, int _iAarray2D[_ArrayA2D_ROW_Size][_ArrayA2D_COLUMN_Size])
{
    for(size_t i = 0; i < _ArrayA2D_ROW_Size; i += 1)
    {
        for(size_t j = 0; j < _ArrayA2D_COLUMN_Size; j += 1)
        {
            printf("Please enter the value of the A[%d,%d](integer): ", i + 1, j + 1);
            scanf("%d", &_iAarray2D[i][j]);
        }
    }
} // end storeAarray2D

void storeBarray2D(int _ArrayB2D_ROW_Size, int _ArrayB2D_COLUMN_Size, int _iBarray2D[_ArrayB2D_ROW_Size][_ArrayB2D_COLUMN_Size])
{
    for(size_t i = 0; i < _ArrayB2D_ROW_Size; i += 1)
    {
        for(size_t j = 0; j < _ArrayB2D_COLUMN_Size; j += 1)
        {
            printf("Please enter the value of the B[%d,%d](integer): ", i + 1, j + 1);
            scanf("%d", &_iBarray2D[i][j]);
        }
    }
} // // end storeBarray2D

void multiply2DArray(int _ArrayA2D_ROW_Size, int _ArrayA2D_COLUMN_Size, int _ArrayB2D_ROW_Size, int _ArrayB2D_COLUMN_Size, int _iAarray2D[_ArrayA2D_ROW_Size][_ArrayA2D_COLUMN_Size], int _iBarray2D[_ArrayB2D_ROW_Size][_ArrayB2D_COLUMN_Size], int _iMultiArray2D[_ArrayA2D_ROW_Size][_ArrayB2D_COLUMN_Size])
{
    for(size_t i = 0; i < _ArrayA2D_ROW_Size; i += 1)
    {
        for(size_t j = 0; j < _ArrayB2D_COLUMN_Size; j += 1)
        {
            _iMultiArray2D[i][j] = _iAarray2D[i][0] * _iBarray2D[0][j] + _iAarray2D[i][1] * _iBarray2D[1][j];
        }
    }
} // end multiply2DArray

void printArray2D(int _row_Size, int _column_Size, int _Array[_row_Size][_column_Size])
{
    for(size_t i = 0; i < _row_Size; i += 1)
    {
        for(size_t j = 0; j < _column_Size; j += 1)
        {
            if(j == _column_Size - 1)
            {
                printf(" %d\n", _Array[i][j]);
            }
            else
            {
                printf(" %d", _Array[i][j]);
            }
        }
    }
} // end printArray2D
