/*
1. square pattern
2. diamond pattern
3. square pattern with stars
*/

#include <stdio.h>

// function prototype
void initiArray2D(size_t squareSIZE, int Array2D[squareSIZE][squareSIZE]); // initialize array2D
size_t defSquareNUM(void); // ensure valid square number
size_t defSquareSize(void); // ensure valid square size
size_t defDiamondSIZE(void); // ensure valid diamond size
void SquareArray_F1(size_t squareSIZE, int printNUM, int Array2D[squareSIZE][squareSIZE]); // decide arr2D_F1 pattern
void printArray2D(size_t squareSIZE, int Array2D[squareSIZE][squareSIZE]); // print out square
void diamondArray2D(size_t userEnterSIZE, size_t diamondSquareSIZE, int diamond2D[diamondSquareSIZE][diamondSquareSIZE]); // define diamond
void printDiamondArray2D(size_t squareSIZE, int Array2D[squareSIZE][squareSIZE]); // print out diamond
size_t defSquareF3(void); // ensure F3 valid square size
void square_starArray2D(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // decide array2D_F3 content
void printSquareStarArray2D(size_t SquareSIZE, int Array2D[SquareSIZE][SquareSIZE]); // print out the square with stars

// start main
int main(void)
{
    int iFunctionNUM = 0;
    size_t stPrintNum_F1 = 0;
    size_t stSquareSIZE_F1 = 0;
    size_t stSquareSIZE_F2 = 0;
    // stSquareSIZE_F2 = defDiamondSIZE();
    // int iDiamondArray2D[stSquareSIZE_F2][stSquareSIZE_F2];
    // initiArray2D(stSquareSIZE_F2, iDiamondArray2D);

    // intro str
    printf("Please choose which pattern you want to print: \n");
    puts("1. Square pattern");
    puts("2. Diamond pattern");
    puts("3. Square pattern with stars");
    puts("4. End program\n");

    do
    {
        printf("Enter the pattern number: "); // prompt user enter the pattern number
        scanf("%d", &iFunctionNUM); // read and store the num
        
        if(iFunctionNUM == 1)
        {
            puts("Square pattern:");
            stPrintNum_F1 = defSquareNUM(); // ensure the number between 0 and 9
            stSquareSIZE_F1 = defSquareSize(); // ensure the square size
            int iSquare2D[stSquareSIZE_F1][stSquareSIZE_F1]; // declare arr2D
            initiArray2D(stSquareSIZE_F1, iSquare2D); // initi arr2D

            SquareArray_F1(stSquareSIZE_F1, stPrintNum_F1, iSquare2D); // deal with the arr2D pattern
            printArray2D(stSquareSIZE_F1, iSquare2D); // print out the pattern
        }
        else if(iFunctionNUM == 2)
        {
            puts("Diamond pattern:");
            size_t stUSER_DiamondSIZE = defDiamondSIZE();
            stSquareSIZE_F2 = stUSER_DiamondSIZE * 2 - 1; // declare the square size
            int iDiamond2D[stSquareSIZE_F2][stSquareSIZE_F2]; // declare the arr2D
            initiArray2D(stSquareSIZE_F2, iDiamond2D); // initi the arr2D

            diamondArray2D(stUSER_DiamondSIZE, stSquareSIZE_F2, iDiamond2D); // decide the pattern of diamond
            printDiamondArray2D(stSquareSIZE_F2, iDiamond2D); // print out the diamond
        }
        else if(iFunctionNUM == 3)
        {
            puts("Square pattern with stars:");
            printf("Enter the size you want ");
            size_t stUserEnterSIZE = defSquareF3(); // read and store the value of the square size
            int iSquareWithStarArray2D[stUserEnterSIZE][stUserEnterSIZE]; // declare the square arr2D
            initiArray2D(stUserEnterSIZE, iSquareWithStarArray2D); // initi the square arr2D

            square_starArray2D(stUserEnterSIZE, iSquareWithStarArray2D); // decide the pattern of the square with stars
            printSquareStarArray2D(stUserEnterSIZE, iSquareWithStarArray2D); // print out the square with stars
        }
        else if(iFunctionNUM == 4)
        {
            puts("End the program.");
        }                
        else
        {
            puts("Invalid number...");
        } // end if           
        
    } while (iFunctionNUM != 4); // end do while

    printf("Goodbye.\n");
} // end main

// def function
void initiArray2D(size_t _squareSIZE, int _Array2D[_squareSIZE][_squareSIZE])
{
    for(size_t row = 0; row < _squareSIZE; row += 1)
    {
        for(size_t col = 0; col < _squareSIZE; col += 1)
        {
            _Array2D[row][col] = 0;
        } // end col
    } // end row
} // end initiArray2D

size_t defSquareNUM(void)
{
    size_t iSuarenum = 0;

    do
    {
        printf("Please enter the number you want to print out (0~9): ");
        scanf("%d", &iSuarenum);

        if(iSuarenum < 0 || iSuarenum > 9)
        {
            printf("Invalid number...\n");
        } // end if
    } while (iSuarenum < 0 || iSuarenum > 9);
    
    return iSuarenum;
} // end defSquareNUM

size_t defSquareSize(void)
{
    size_t SquareSIZE;

    do
    {
        printf("The length of the square you want it to be: ");
        scanf("%d", &SquareSIZE);

        if(SquareSIZE <= 0)
        {
            printf("Invalid number...\n");
        } // end if 
    } while (SquareSIZE <= 0);

    return SquareSIZE;
} // end defSquareSize

size_t defDiamondSIZE(void)
{
    size_t stDiamondSIZE = 0;

    do
    {
        printf("Enter the diamond size (2~9) : ");
        scanf("%d", &stDiamondSIZE);

        if(stDiamondSIZE < 2 || stDiamondSIZE > 9)
        {
            printf("Invalid size...");
        } // end if

    } while (stDiamondSIZE < 2 || stDiamondSIZE > 9);

    return stDiamondSIZE;
} // end defDiamondSIZE

void SquareArray_F1(size_t _squareSIZE, int _printNUM, int _Array2D[_squareSIZE][_squareSIZE])
{
    for(size_t row = 0; row < _squareSIZE; row += 1)
    {
        if(row == 0 || row == _squareSIZE - 1)
        {
            for(size_t col = 0; col < _squareSIZE; col += 1)
            {
                _Array2D[row][col] = _printNUM;
            } // end col
        }
        else
        {
            for(size_t col = 0; col < _squareSIZE; col += 1)
            {
                if(col == 0 || col == _squareSIZE - 1)
                {
                    _Array2D[row][col] = _printNUM;
                }
                else
                {
                    _Array2D[row][col] = -1;
                } // end if
            } // end col
        } // end if
    } // end row
} // end SquareArray_F1

void printArray2D(size_t _squareSIZE, int _Array2D[_squareSIZE][_squareSIZE])
{
    for(size_t row = 0; row < _squareSIZE; row += 1)
    {
        for(size_t col = 0; col < _squareSIZE; col += 1)
        {
            if(_Array2D[row][col] < 0)
            {
                printf("  ");
            }
            else
            {
                printf(" %d", _Array2D[row][col]);
            } // end if
        } // end col
        puts(""); // add new line
    } // end row
} // end printArray2D

void diamondArray2D(size_t _userEnterSIZE, size_t _diamondSquareSIZE, int _diamond2D[_diamondSquareSIZE][_diamondSquareSIZE])
{
    int i1stROW_1st_Num = 1 - _userEnterSIZE;

    for(size_t row = 0; row < _diamondSquareSIZE; row += 1)
    {
        if(row <= _userEnterSIZE - 1)
        {
            for(size_t col = 0; col < _diamondSquareSIZE; col += 1)
            {
                if(col <= _userEnterSIZE - 1)
                {
                    i1stROW_1st_Num += 1;

                    _diamond2D[row][col] = i1stROW_1st_Num;
                }
                else
                {
                    i1stROW_1st_Num -= 1;

                    _diamond2D[row][col] = i1stROW_1st_Num;
                } // end if
            } // end col
        }
        else
        {
            i1stROW_1st_Num -= 2;

            for(size_t col = 0; col < _diamondSquareSIZE; col += 1)
            {
                if(col <= _userEnterSIZE - 1)
                {
                    i1stROW_1st_Num += 1;

                    _diamond2D[row][col] = i1stROW_1st_Num;
                }
                else
                {
                    i1stROW_1st_Num -= 1;

                    _diamond2D[row][col] = i1stROW_1st_Num;
                } // end if
            } // end col
        } // end if
    } // end row
} // end diamondArray2D

void printDiamondArray2D(size_t _squareSIZE, int _Array2D[_squareSIZE][_squareSIZE])
{
    for(size_t row = 0; row < _squareSIZE; row += 1)
    {
        for(size_t col = 0; col < _squareSIZE; col += 1)
        {
            if(_Array2D[row][col] <= 0)
            {
                printf("  ");
            }
            else
            {
                printf(" %d", _Array2D[row][col]);
            } // end if
        } // end col
        puts(""); // add new line
    } // end row
} // end printDiamondArray2D

size_t defSquareF3(void)
{
    size_t userenterNUM = 0;
    do
    {
        printf("Please enter the size (over or equal to 2): ");
        scanf("%d", &userenterNUM);

        if(userenterNUM < 2)
        {
            printf("Invalid number...\n");
        } // end if
    } while (userenterNUM < 2);
    
    return userenterNUM;
} // end defSquareF3

void square_starArray2D(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    unsigned int uiNumContent = 0;
    int iDesideINCREorDECRE = 0;

    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            if((row + col) % 2 == 1)
            {
                _Array2D[row][col] = 0;
            }
            else
            {
                if(_Array2D[row][col] < 9 && iDesideINCREorDECRE == 0)
                {
                    uiNumContent += 1;
                    
                    _Array2D[row][col] = uiNumContent;

                    if(_Array2D[row][col] == 9)
                    {
                        iDesideINCREorDECRE += 1;
                    } // end if
                }
                else
                {
                    uiNumContent -= 1;

                    _Array2D[row][col] = uiNumContent;

                    if(_Array2D[row][col] == 1)
                    {
                        iDesideINCREorDECRE -= 1;
                    } // end if
                } // end if

            } // end if
        } // end col
    } // end row
} // end square_starArray2D

void printSquareStarArray2D(size_t _SquareSIZE, int _Array2D[_SquareSIZE][_SquareSIZE])
{
    for(size_t row = 0; row < _SquareSIZE; row += 1)
    {
        for(size_t col = 0; col < _SquareSIZE; col += 1)
        {
            if(_Array2D[row][col] <= 0)
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
} // end printSquareStarArray2D
