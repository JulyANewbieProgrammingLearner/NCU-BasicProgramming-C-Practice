#include <stdio.h>

// function prototype
void printArray(int index_size, int array[index_size]); // print Array
void initiArray(int index_size, int array[index_size]); // initialize array
void storeUserInput(int index_size, int array[index_size]); // user enter every elements
int checkSize(int UserEnterNum); // ensure array size valid

// start main
int main(void)
{
    int uUerSize; // def uUerSize
    printf("Please enter the size of the array you want: "); // prompt user enter Arr size
    scanf("%u", &uUerSize);
    uUerSize = checkSize(uUerSize); // ensure array size valid

    int iArray[uUerSize]; // def array

    initiArray(iArray, uUerSize); // initialize array

    storeUserInput(iArray, uUerSize); // store input into array

    printArray(iArray, uUerSize); // print out array

} // end main

// def function
void printArray(int _iArrayName[], int _luIndex_size)
{
    for(size_t j = 0; j < _luIndex_size; j += 1)
    {
        printf("Array[%u]: %d\n", j, _iArrayName[j]);
    }
}

void initiArray(int _index_size, int _array[_index_size])
{
    for(size_t j = 0; j < _index_size; j += 1)
    {
        _array[j] = 0;
    }
}

void storeUserInput(int _index_size, int _array[_index_size])
{
    for(size_t j = 0; j < _index_size; j += 1)
    {
        printf("Please enter No.%u number(integer): ", j + 1);
        scanf("%d", &_array[j]);
    }
} // end storeUserInput

int checkSize(int _UserEnterNum)
{
    while(_UserEnterNum < 1)
    {
        printf("Please enter the size of the array you want: ");
        scanf("%u", &_UserEnterNum);
		
		if(_UserEnterNum < 1)
		{
			printf("Invalid size...\n");
		} // end if
    }

    return _UserEnterNum;
} // end checkSize

