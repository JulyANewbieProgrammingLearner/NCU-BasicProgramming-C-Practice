/*
Calculate loop(menu num != 1)
def ArraySize by the user
input numers to store in arr1D
fAver store the value of average of elements
print fAver
*/

#include <stdio.h>

// function prototype
size_t defArrSize(void); // read and store the size of arr1D
void initiArr1D(size_t NumofStudents, int arr[NumofStudents]); // initi arr1D
void selfDefArr1D(size_t NumofStudents, int arr[NumofStudents]); // def arr1D by user
void printArr1D(size_t _NumofStudents, int _arr[_NumofStudents]); // print arr1D
size_t defGrade(void); // control the value of elements between 0 to 100
float averageGrade(size_t NumofStudents, int arr[NumofStudents]); // calculate the average score of class

// start main
int main(void)
{
    int iFunctionNum = 0;
    do
    {
        // intro string
        printf("This is the program that can help you calculate the value of class average.\n ");
        printf("You will need to enter the number of students in the class and the score of each student.\n");

        size_t ArrSize = defArrSize();
        int Arr[ArrSize]; // declare array
        initiArr1D(ArrSize, Arr); // initi array

        if(ArrSize == 1)
        {
            printf("Enter %d grade\n", ArrSize);
        }
        else
        {
            printf("Enter %d grades\n", ArrSize);
        } // end if

        selfDefArr1D(ArrSize, Arr); // def arr1D by user

        printArr1D(ArrSize, Arr); // check and show if arr1D functions correctly

        float fAverage = averageGrade(ArrSize, Arr); // cal and store the aver to variables
        printf("The average score of the class is %.2f .\n", fAverage); // print out the result

        printf("Do you want to end the program ? (enter 1 to end) : ");
        scanf("%d", &iFunctionNum);
    } while (iFunctionNum != 1);

    puts("Goodbye.\n");
} // end main

// def function
size_t defArrSize(void)
{
    size_t size = 0;
    do
    {
        printf("Enter the number of students: ");
        scanf("%d", &size);

        if(size < 1)
        {
            printf("Invalid number...\n");
        } // end if
    } while (size < 1); // end while
    
    return size;
} // end defArrSize

void initiArr1D(size_t _NumofStudents, int _arr[_NumofStudents])
{
    for(size_t i = 0; i < _NumofStudents; i += 1)
    {
        _arr[i] = 0;
    } // end arr
} // end initiArr1D

void selfDefArr1D(size_t _NumofStudents, int _arr[_NumofStudents])
{
    for(size_t i = 0; i < _NumofStudents; i += 1)
    {
        _arr[i] = defGrade();
    } // end arr
} // end selfDefArr

void printArr1D(size_t _NumofStudents, int _arr[_NumofStudents])
{
    for(size_t i = 0; i < _NumofStudents; i += 1)
    {
        printf(" %d", _arr[i]);
    } // end arr
    puts(""); // add new line    
} // end printArr1D

size_t defGrade(void)
{
    size_t Grade = 0;
    do
    {
        printf("Enter grade: ");
        scanf("%d", &Grade);

        if(Grade < 0 || Grade > 100)
        {
            printf("Invalid grade...\n");
        } // end if

    } while (Grade < 0 || Grade > 100);
    
    return Grade;
} // end defGrade

float averageGrade(size_t _NumofStudents, int _arr[_NumofStudents])
{
    float Average = 0;

    for(size_t i = 0; i < _NumofStudents; i += 1)
    {
        Average += _arr[i];
    } // end arr

    Average = Average / _NumofStudents;

    return Average;  
} // end averageGrade

