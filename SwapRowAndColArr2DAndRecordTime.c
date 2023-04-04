#include <stdio.h>
#define FrequencyArraySIZE 11 // def constant

// function prototype
int ensureRowSizeValid(int Row_Size); // ensure row size valid
int ensureColumnSizeValid(int Column_Size); // ensure column size valid
void initiArray(int rowSize, int columnSize, int array[rowSize][columnSize]); // initialize Array2D
void ask_User_Def_ElementValue_2Darray(int rowSize, int columnSize, int array[rowSize][columnSize]);
int ensureValue_MIN1_MAX10(int rowNum, int columnNum, int value);
void printArray2D(int rowSize, int columnSize, int array[rowSize][columnSize]);
void RowColumnExchange_to_NewArray(int rowSize, int columnSize, int array[rowSize][columnSize], int array2[columnSize][rowSize]);
void frequency(int rowSize, int columnSize,int FSize, int array[rowSize][columnSize], int FArray1D[FSize]);
void printFrequencyArray1D(int FSize, int FArray1D[FSize]);

// start main
int main(void)
{
    int iRow_Size = 0; // def and initialize row
    int iColumn_Size = 0; // def and initialize column
    
    printf("Please enter the row size(1 ~ 4): ");
    scanf("%d", &iRow_Size);
    iRow_Size = ensureRowSizeValid(iRow_Size); // ensure row size valid

    printf("Please enter the column size(1 ~ 4): ");
    scanf("%d", &iColumn_Size);
    iColumn_Size = ensureColumnSizeValid(iColumn_Size); // ensure column size valid

    int iArray2D[iRow_Size][iColumn_Size]; // def Array2D

    initiArray(iRow_Size, iColumn_Size, iArray2D); // initialize Array2D

    ask_User_Def_ElementValue_2Darray(iRow_Size, iColumn_Size, iArray2D); // prompt user enter valid number

    printf("Original two dimensional array: \n");
    printArray2D(iRow_Size, iColumn_Size, iArray2D); // print out original Array2D

    puts(""); // add new line

    int iFrequencyArray1D[FrequencyArraySIZE] = {0}; // def and initialize FrequencyArray

    frequency(iRow_Size, iColumn_Size, FrequencyArraySIZE, iArray2D, iFrequencyArray1D); // calculate frequency
    printFrequencyArray1D(FrequencyArraySIZE, iFrequencyArray1D); // print out result

    puts(""); // add new line

	// def variables
    int iRow_trans = iColumn_Size;
    int iColummn_trans = iRow_Size;
    int iArray2D_transfer[iRow_trans][iColummn_trans];

    initiArray(iRow_trans, iColummn_trans, iArray2D_transfer); // initialize initiArray

    RowColumnExchange_to_NewArray(iRow_Size, iColumn_Size, iArray2D, iArray2D_transfer); // Swap row and column

    printf("Swap row and column to form new two dimensional array: \n");
    printArray2D(iRow_trans, iColummn_trans, iArray2D_transfer); // print out result
} // end main

// def function
int ensureRowSizeValid(int _iRow_Size)
{
    while(_iRow_Size < 1 || _iRow_Size > 4)
    {
        printf("Please enter the row size(1 ~ 4): ");
        scanf("%d", &_iRow_Size);
		
		if(_iRow_Size < 1 || _iRow_Size > 4)
		{
			printf("Invalid row size...\n");
		} // end if
    }

    return _iRow_Size;
} // end ensureRowSizeValid

int ensureColumnSizeValid(int _iColumn_Size)
{
    while(_iColumn_Size < 1 || _iColumn_Size > 4)
    {
        printf("Please enter the row size(1 ~ 4): ");
        scanf("%d", &_iColumn_Size);
		
		if(_iColumn_Size < 1 || _iColumn_Size > 4)
		{
			printf("Invalid column size...\n");
		} // end if
    }

    return _iColumn_Size;
} // end ensureColumnSizeValid

void initiArray(int _rowSize, int _columnSize, int _array[_rowSize][_columnSize])
{
    for(size_t r = 0; r < _rowSize; r += 1)
    {
        for(size_t c = 0; c < _columnSize; c += 1)
        {
            _array[r][c] = 0;
        }
    }
} // end initiArray

void ask_User_Def_ElementValue_2Darray(int _rowSize, int _columnSize, int _array[_rowSize][_columnSize])
{
    for(size_t r = 0; r < _rowSize; r += 1)
    {
        for(size_t c = 0; c < _columnSize; c += 1)
        {
            printf("Please enter the value of element[%d,%d] in integer (between 1 and 10, inclusive): ", r + 1, c + 1);
            scanf("%d", &_array[r][c]);

            _array[r][c] = ensureValue_MIN1_MAX10(r, c, _array[r][c]); // ensure the value of element valid
        } // end col
    } // end row
} // end ask_User_Def_ElementValue_2Darray

int ensureValue_MIN1_MAX10(int _rowNum, int _columnNum, int _value)
{
    while(_value < 1 || _value > 10)
    {
        printf("Please enter the value of element[%d,%d] in integer again (between 1 and 10, inclusive): ", _rowNum + 1, _columnNum + 1);
        scanf("%d", &_value);
    }

    return _value;
} // end ensureValue_MIN1_MAX10

void printArray2D(int _rowSize, int _columnSize, int _array[_rowSize][_columnSize])
{
    for(size_t r = 0; r < _rowSize; r += 1)
    {
        for(size_t c = 0; c < _columnSize; c += 1)
        {
            if(c == _columnSize - 1)
            {
                printf(" %d\n", _array[r][c]);
            }
            else
            {
                printf(" %d", _array[r][c]);
            }
        }
    }
} // end printArray2D

void RowColumnExchange_to_NewArray(int _rowSize, int _columnSize, int _array[_rowSize][_columnSize], int _array2[_columnSize][_rowSize])
{
    for(size_t r = 0; r < _rowSize; r += 1)
    {
        for(size_t c = 0; c < _columnSize; c += 1)
        {
            _array2[c][r] = _array[r][c];
        }
    }
} // end RowColumnExchange_to_NewArray

void frequency(int _rowSize, int _columnSize,int _FSize, int _array[_rowSize][_columnSize], int _FArray1D[_FSize])
{
    for(size_t r = 0; r < _rowSize; r += 1)
    {
        for(size_t c = 0; c < _columnSize; c += 1)
        {
            _FArray1D[_array[r][c]] += 1;
        }
    }
} // end frequency

void printFrequencyArray1D(int _FSize, int _FArray1D[_FSize])
{
    for(size_t k = 1; k < _FSize; k += 1)
    {
        switch(k)
        {
            case 1:
                printf(" 1 appear time: %d\n", _FArray1D[1]);
                    break;
            case 2:
                printf(" 2 appear time: %d\n", _FArray1D[2]);
                    break;
            case 3:
                printf(" 3 appear time: %d\n", _FArray1D[3]);
                    break;
            case 4:
                printf(" 4 appear time: %d\n", _FArray1D[4]);
                    break;
            case 5:
                printf(" 5 appear time: %d\n", _FArray1D[5]);
                    break;
            case 6:
                printf(" 6 appear time: %d\n", _FArray1D[6]);
                    break;
            case 7:
                printf(" 7 appear time: %d\n", _FArray1D[7]);
                    break;
            case 8:
                printf(" 8 appear time: %d\n", _FArray1D[8]);
                    break;
            case 9:
                printf(" 9 appear time: %d\n", _FArray1D[9]);
                    break;
            case 10:
                printf(" 10 appear time: %d\n", _FArray1D[10]);
                    break;
        } // end switch
    } // end for
} // end printFrequencyArray1D
