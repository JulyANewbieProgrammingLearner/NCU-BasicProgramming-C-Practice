/*
enter a num iNum, domain: 1 ~ 9
enter a random num that is the multiple of iNum
if yes -> congrats
if no -> enter another num that is the multiple of iNum
*/
#include <stdio.h>

// function prototype
void introduceStr(void); // def intro string
int checkNum(int number1); // ensure the number between 1 and 9
void isMultiple(int number1, int number2); // judge whether the input number is the multiple number

// start main
int main(void)
{
    int iNum = 0; // def and initialize iNum
    int iMultiNum = 0; // def and initialize iMultiNum

    introduceStr();

    printf("Please enter a number for N: "); // prompt user enter
    scanf("%d", &iNum); // read and store entry

    iNum = checkNum(iNum);

    printf("Please enter a multiple number of %d: ", iNum); // prompt user enter another num
    scanf("%d", &iMultiNum); // read and store entry

    isMultiple(iNum, iMultiNum);
} // end main

void introduceStr(void)
{
    printf("This program assists you to find the multiple of N.\n");
    printf("N must be between 1 and 9.\n"); // end intro str
}
int checkNum(int _iNum)
{
    // start 1st while_checking
    while(_iNum < 1 || _iNum > 9)
    {
        printf("N must be between 1 and 9. Please enter again: "); // prompt user enter
        scanf("%d", &_iNum); // read and store entry
    } // end 1st while_checking

    return _iNum;
}
void isMultiple(int _iNum, int _iMultiNum)
{
    // start 2nd while_checking
    while(_iMultiNum % _iNum != 0)
    {
        printf("%d is not a multiple of ", _iMultiNum);
        printf("%d. Please enter again: ", _iNum);
        scanf("%d", &_iMultiNum);
    } // end 2nd while_checking

    printf("Congratulation! You find a multiple of %d", _iNum); // congratulation str
}
