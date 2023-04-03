/*
work flow:
input the squareSIZE (>0)
fill elements
print array2D
print off-diagnosal the sum
*/

#include <stdio.h>

// function prototype
size_t defSquareSIZE(void); // ensure SquareSize a positive number
void initiArray2D(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // initialize array2D
void fillElements2D(size_t row, size_t col, int arr[row][col]); // user enter the value of the elements of the array2D
void printArr2D(size_t row, size_t col, int arr[row][col]); // print out the matrix
void initiArray1D(size_t size, int array1D[size]); //initialize array1D
void calculateOffDiagonal(size_t row, size_t col, int arr[row][col], size_t sum_size, int sum[sum_size]); // calculate the value of the sum of off-diagonal
void printOffDiagonalsSum(size_t size, int sum[size]); // print out the off-diagonal's sum in array1D form

// start main
int main(void)
{
	printf("The program will print out the matrix and the array of each sum of off-diagonal.\n"); // intro string
	
    size_t SquareSize = defSquareSIZE(); // def SquareSize
    int iArray2D[SquareSize][SquareSize]; // declare Arr2D
    initiArray2D(SquareSize, iArray2D); // initialize Arr2D

    size_t row_size = SquareSize;
    size_t col_size = SquareSize;

    fillElements2D(row_size, col_size, iArray2D); // user enter elements
    puts(""); // add new line

    printf("The matrix is %dx%d and the elements are: \n", row_size, col_size);
    printArr2D(row_size, col_size, iArray2D);

    printf("Results: \n");

    size_t sumSize = 2 * SquareSize - 1; // def the number of elements of new Arr1D

    printf("There are %d off-diagonals, and the sum of each off-diagonal is\n", sumSize);

    int iSum1D[sumSize]; // declare iSum1D
    initiArray1D(sumSize, iSum1D); // initialize iSum1D
    calculateOffDiagonal(row_size, col_size, iArray2D, sumSize, iSum1D); // calculate each value of elements of off-diagnosal Arr1D
    printOffDiagonalsSum(sumSize, iSum1D); // print out the Arr1D
} // end main

// def function
size_t defSquareSIZE(void)
{
    size_t UserNum = 0; // declare and initialize variable

    do
    {
        printf("Input the size of matrix (must over 0): ");
        scanf("%d", &UserNum);

        if(UserNum <= 0)
        {
            printf("Invalid number...\n");
        } // end if
    } while (UserNum <= 0);
    
    return UserNum;
} // end defSquareSIZE

void initiArray2D(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _Array2D[row][col] = 0;
        } // end col
    } // end row
} // end initiArray2D

void fillElements2D(size_t row, size_t col, int arr[row][col])
{
    printf("Please enter elements: ");

    for(size_t i = 0; i < row; i += 1)
    {
        for(size_t j = 0; j < col; j += 1)
        {
            scanf("%d", &arr[i][j]);
        } // end col
    } // end row
} // end fillElements2D

void printArr2D(size_t row, size_t col, int arr[row][col])
{
    for(size_t i = 0; i < row; i += 1)
    {
        for(size_t j = 0; j < col; j += 1)
        {
            printf(" %d", arr[i][j]);
        } // end col
        puts(""); // add new line
    } // end row
} // end printArr2D

void initiArray1D(size_t _size, int _array1D[_size])
{
    for(size_t i = 0; i < _size; i += 1)
    {
        _array1D[i] = 0;
    } // end array
} // end initiArray1D

void calculateOffDiagonal(size_t row, size_t col, int arr[row][col], size_t sum_size, int sum[sum_size])
{
    for(size_t i = 0; i < row; i += 1)
    {
        for(size_t j = 0; j < col; j += 1)
        {
            size_t k = i + j;

            sum[k] = sum[k] + arr[i][j];
        } // end col
    } // end row
} // end calculateOffDiagonal

void printOffDiagonalsSum(size_t size, int sum[size])
{
    for(size_t i = 0; i < size - 1; i += 1)
    {
        printf(" %d,", sum[i]);
    }
    printf(" %d.\n", sum[size - 1]);
} // end printOffDiagonalsSum
