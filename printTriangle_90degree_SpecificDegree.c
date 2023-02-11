/*
program's function:
1. receive square size
2. print triangle
3. rotate 90 degree
4. rotate specific degree
*/

#include <stdio.h>

// function prototype
size_t defTriangleSIZE(void); // ensure valid triangle size
void initiArray2D(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // initialize array2D
void TriangleArray(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // define array2D content
void printArray2D(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // print out the pattern
void Rotate90Degree_clockwise(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE], int tempArray2D[SquareSIZE][SquareSIZE]); // rotate the pattern clockwise
int defSpecificDegree(void); // ensure the degree to be specific degree
void Rotate90Degree_counterclockwise(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE], int tempArray2D[SquareSIZE][SquareSIZE]); // rotate the pattern counterclockwise
void RotateSpecificDegree(size_t SquareSIZE, int SpecificDegree, int Array2D[SquareSIZE][SquareSIZE], int tempArray2D[SquareSIZE][SquareSIZE]); // rotate the pattern in specific degree

// start main
int main(void)
{
    size_t iTriangle_Size = 0;

    iTriangle_Size = defTriangleSIZE();

    int iArray2d[iTriangle_Size][iTriangle_Size];
    initiArray2D(iTriangle_Size, iArray2d);
    int tempArray2d[iTriangle_Size][iTriangle_Size];
    initiArray2D(iTriangle_Size, tempArray2d);

    int iSepecificDegree_user = 0;

    int iFuncNum = 0;

    printf("This program will do several things:\n");
    puts("1. Print triangle");
    puts("2. Rotate 90 degree");
    puts("3. Rotate specific degree");
    puts("4. End program");    

    do // 1. triangle ; 2. rotate 90 degree ; 3. rotate specific degree ; 4. end the program
    {
        printf("Which program you want to execute: ");
        scanf("%d", &iFuncNum);

        switch(iFuncNum)
        {
            case 1:
                printf("triangle\n");
                TriangleArray(iTriangle_Size, iArray2d);
                printArray2D(iTriangle_Size, iArray2d);
                    break;
            case 2:
                printf("Rotate 90 \n");
                Rotate90Degree_clockwise(iTriangle_Size, iArray2d, tempArray2d);
                printArray2D(iTriangle_Size, iArray2d);
                    break;
            case 3:
                printf("Rotate specific degree\n");
                iSepecificDegree_user = defSpecificDegree();
                RotateSpecificDegree(iTriangle_Size, iSepecificDegree_user, iArray2d, tempArray2d);
                printArray2D(iTriangle_Size, iArray2d);
                    break;
            case 4:
                printf("End program\n");
                    break;
            default:
                printf("Invalid function number...\n");
                    break;
        }
    } while (iFuncNum != 4);

    printf("Goodbye.\n");
} // end main

// def function
size_t defTriangleSIZE(void)
{
    int iTriangleSize = 0;

    do
    {
        printf("Please enter the triangle size (1~10): ");
        scanf("%d", &iTriangleSize);

        if(iTriangleSize < 1 || iTriangleSize > 10)
        {
            printf("Invalid size ... ");
            printf("Please enter again.\n");
        } // end if
    } while (iTriangleSize < 1 || iTriangleSize > 10);

    return iTriangleSize;
} // end defTriangleSIZE

void initiArray2D(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE ; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _Array2D[row][col] = 0;
        } // end col
    } // end row
} // end initiArray2D

void TriangleArray(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            if(col <= row)
            {
                _Array2D[row][col] = 1;
            }
            else
            {
                _Array2D[row][col] = 0;
            } // end if
        } // end col
    } // end row
} // end printTriangle

void printArray2D(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            if(_Array2D[row][col] == 1)
            {
                printf(" *");
            }
            else
            {
                printf(" %d", _Array2D[row][col]);
            } // end if
        } // end col
        puts(""); // add new line
    } // end row
} // end printArray2D

void Rotate90Degree_clockwise(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE], int _tempArray2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _tempArray2D[col][_SquareSIZE - row - 1] = _Array2D[row][col];
        } // end col
    } // end row

    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _Array2D[row][col] = _tempArray2D[row][col];
        } // end col
    } // end row
} // end Rotate90Degree_clockwise

void Rotate90Degree_counterclockwise(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE], int _tempArray2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _tempArray2D[_SquareSIZE - col - 1][row] = _Array2D[row][col];
        } // end col
    } // end row

    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            _Array2D[row][col] = _tempArray2D[row][col];
        } // end col
    } // end row    
} // end Rotate90Degree_counterclockwise

int defSpecificDegree(void)
{
    int iUSERDegree = 0;

    do
    {
        printf("Please enter the degree you want (the multiple number of 90) in degree: ");
        scanf("%d", &iUSERDegree);

        if(iUSERDegree % 90 != 0)
        {
            printf("Invalid number...\n");
        } // end if
    } while (iUSERDegree % 90 != 0);

    return iUSERDegree;
} // end defSpecificDegree

void RotateSpecificDegree(size_t _SquareSIZE, int _SpecificDegree, int _Array2D[_SquareSIZE][_SquareSIZE], int _tempArray2D[_SquareSIZE][_SquareSIZE])
{
    int iRotateCounter = _SpecificDegree / 90;

    if(iRotateCounter < 0)
    {
        while(iRotateCounter < 0)
        {
            Rotate90Degree_counterclockwise(_SquareSIZE, _Array2D, _tempArray2D);

            iRotateCounter += 1;
        } // end while
    } // end if

    if(iRotateCounter > 0)
    {
        while(iRotateCounter > 0)
        {
            Rotate90Degree_clockwise(_SquareSIZE, _Array2D, _tempArray2D);

            iRotateCounter -= 1;
        } // end while
    } // end if
} // end RotateSpecificDegree

