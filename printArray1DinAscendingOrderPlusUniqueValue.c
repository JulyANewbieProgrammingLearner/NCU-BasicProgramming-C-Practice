/*
work flow:
1. user size array
2. value enter
3. present original array
4. present array in ascending order
5. present array without the repeating value
*/

#include <stdio.h>

// function prototype
size_t defArray1DSIZE(void); // def array1D size
void initiArray1D(size_t arraySIZE, int Array1D[arraySIZE]); // initialize array1D 
void selfDefArray1D_value(size_t arraySIZE, int Array1D[arraySIZE]); // user define the content of array1D content
void printfArray1D(size_t arraySIZE, int Array1D[arraySIZE]); // print out the pattern
void sortArray1D_AscendingORDER(size_t arraySIZE, int Array1D[arraySIZE]); // sort array1D in ascending order
void printUniqueArray1D(size_t size, int Array1D[size]); // print the UniqueArrayD


// start main
int main(void)
{
    size_t Array1D_size = defArray1DSIZE(); // read and store the value of size
    int iArray1D[Array1D_size]; // declare the arr1D
    initiArray1D(Array1D_size, iArray1D); // initi the arr1D

    selfDefArray1D_value(Array1D_size, iArray1D); // read and store the value of element of arr1D
    printf("The original array: ");
    printfArray1D(Array1D_size, iArray1D); // print out the num in the form of arr1D, which user entered previously
    
    sortArray1D_AscendingORDER(Array1D_size, iArray1D); // sort the element in ascending order
    printfArray1D(Array1D_size, iArray1D); // print out arr1D (ascending)

    printUniqueArray1D(Array1D_size, iArray1D); // print out the unique arr1D
} // end main

// def function
size_t defArray1DSIZE(void)
{
    size_t Array1DSize = 0;

    do
    {
        printf("Please input the size of the 1D-array: ");
        scanf("%d", &Array1DSize);

        if(Array1DSize <= 1)
        {
            printf("The length of the array must be greater than 1, please input again...\n");
        } // end if
    } while (Array1DSize <= 1);
    
    return Array1DSize;
} // end defArray1DSIZE

void initiArray1D(size_t _arraySIZE, int _Array1D[_arraySIZE])
{
    for(size_t i = 0; i < _arraySIZE; i += 1)
    {
        _Array1D[i] = 0;
    } // end array
} // end initiArray1D

void selfDefArray1D_value(size_t _arraySIZE, int _Array1D[_arraySIZE])
{
    printf("Please enter the number you want: ");
    for(size_t i = 0; i < _arraySIZE; i += 1)
    {
        scanf("%d", &_Array1D[i]);
    } // end array
} // end selfDefArray1D_value

void printfArray1D(size_t _arraySIZE, int _Array1D[_arraySIZE])
{
    printf("[");
    for(size_t i = 0; i < _arraySIZE; i += 1)
    {
        printf(" %d", _Array1D[i]);
    } // end array
    printf(" ]\n");
} // end printfArray1D

void sortArray1D_AscendingORDER(size_t _arraySIZE, int _Array1D[_arraySIZE])
{
    for(size_t i = 0; i < _arraySIZE; i += 1)
    {
        for(size_t j = 0; j < _arraySIZE - 1; j += 1)
        {
            if(_Array1D[j] > _Array1D[j + 1])
            {
                int hold = _Array1D[j];
                _Array1D[j] = _Array1D[j + 1];
                _Array1D[j + 1] = hold;
            } // end if
        } // end column checking in a row
    } // end checking times
} // end sortArray1D_AscendingORDER

void printUniqueArray1D(size_t _size, int _Array1D[_size])
{
    printf("[");
    for(size_t i = 0; i < _size - 1; i += 1)
    {
        if(_Array1D[i] != _Array1D[i + 1])
        {
            printf(" %d", _Array1D[i]);
        } // end array
    }
    printf(" %d", _Array1D[_size - 1]);
    printf(" ]\n");
} // end printUniqueArray1D
