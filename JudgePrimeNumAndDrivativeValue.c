/*
work flow:
1. enter a, b, c, d, x value (b != d)
2. present differential function
3. present differential value 
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// function prototype
float defNumD(float NumB); // let NumD not equal to NumB
float defPOSITIVE_X(void); // ensure NumX a positive num
float calcuDifferentialValue(float numA, float numB, float numC, float numD, float numX); // calculate the derivative result
unsigned int defUserNumber(void); // make user's input stay in the domain
bool isPrime(unsigned int Number); // judge whether number is prime number
unsigned int reverseNum(unsigned int origiNum); // reverse number

// start main
int main(void)
{
	// def and initialize variables
    int ifunctionNUM = 0;
    float fNumA = 0.0;
    float fNumB = 0.0;
    float fNumC = 0.0;
    float fNumD = 0.0;
    float fNumX = 0.0;
    float fNumResult = 0.0;
    size_t uiUserEnterNUM = 0;

    do
    {
        printf("Enter function number: "); // prompt user enter function num
        scanf("%d", &ifunctionNUM);

        if(ifunctionNUM == 1)
        {
            unsigned int stUserInput = defUserNumber(); // ensure the input is in the domain 1111 to 9999
            unsigned int uiJudge = isPrime(stUserInput); // judge whether input is prime number

            if(uiJudge == 0)
            {
                printf("%d is not a prime number.\n", stUserInput);
            }
            else
            {
                unsigned int uiReversedNum = reverseNum(stUserInput); // store the reversed num
                unsigned int uiSecondJudge = isPrime(uiReversedNum); // judge whether reversed num is prime number

                if(uiSecondJudge == 0)
                {
                    printf("%d is a prime number but \"backward\" %d is not.\n", stUserInput, stUserInput);
                }
                else
                {
                    printf("%d is a \"special\" prime number.\n", stUserInput);
                } // end if
            } // end if
        }
        else if(ifunctionNUM == 2)
        {
            printf("DIFFERENTIAL FUNCTION: (ax^b + cx^d, b is not equal to d)\n");
            printf("Enter a number for a: ");
            scanf("%f", &fNumA);
            printf("Enter a number for b: ");
            scanf("%f", &fNumB);
            printf("Enter a number for c: ");
            scanf("%f", &fNumC);
            fNumD = defNumD(fNumB); // avoid NumD equal to NumB
            fNumX = defPOSITIVE_X(); // ensure NumX a positive num

            fNumResult = calcuDifferentialValue(fNumA, fNumB, fNumC, fNumD, fNumX); // calculate
            printf("%f\n", fNumResult); // print out the result
        }
        else if(ifunctionNUM == 3)
        {
            printf("End program...\n");
        }
        else
        {
            printf("Invalid number...\n");
        } // end if
    } while (ifunctionNUM != 3);
    
    printf("Goodbye.\n");
} // end main

// def function
float defNumD(float _NumB)
{
    float NumD;

    do
    {
        printf("Enter a number for d: ");
        scanf("%f", &NumD);

        if(_NumB == NumD)
        {
            printf("d should not equal to b, enter d again...\n");
        } // end if
    } while (_NumB == NumD);
    
    return NumD;
} // end defNumD

float defPOSITIVE_X(void)
{
    float numberX = 0.0;

    do
    {
        printf("Enter a number for x (x > 0): ");
        scanf("%f", &numberX);

        if(numberX <= 0)
        {
            printf("Invalid number...\n");
        } // end if
    } while (numberX <= 0);
    
    return numberX;
} // end defPOSITIVE_X

float calcuDifferentialValue(float _numA, float _numB, float _numC, float _numD, float _numX)
{
	// def and initialize
    float fNewNumA = 0.0;
    float fNewNumB = 0.0;
    float fNewNumC = 0.0;
    float fNewNumD = 0.0;
    float fResult = 0.0;

    fNewNumA = _numA * _numB;
    fNewNumB = _numB - 1;
    fNewNumC = _numC * _numD;
    fNewNumD = _numD - 1;

    fResult = fNewNumA * pow(_numX, fNewNumB) + fNewNumC * pow(_numX, fNewNumD); // cal the result
    
    return fResult;
} // end calcuDifferentialValue

unsigned int defUserNumber(void)
{
    unsigned int userNumber = 0;

    do
    {
        printf("Please enter the number (1111~9999): "); // prompt user enter number between 1111 and 9999
        scanf("%d", &userNumber);

        if(userNumber < 1111 || userNumber > 9999)
        {
            printf("Invalid number...\n");
        } // end if
    } while (userNumber < 1111 || userNumber > 9999);
    
    return userNumber;
} // end defUserNumber

bool isPrime(unsigned int _Number)
{
    unsigned int uiDiviNum = 0; // def and initialize uiDiviNum

    if(_Number == 2)
    {
        return true;
    }
    else if(_Number  % 2 == 0 && _Number != 2)
    {
        return false;
    }
    else if(_Number == 1)
    {
        return false;
    }
    else
    {
        uiDiviNum = (_Number + 1) / 2 - 1;

        for(unsigned int Divi = uiDiviNum; Divi > 2; Divi -= 2)
        {
            if(_Number % Divi == 0)
            {
                return false;
            }
        } // end division
        return true;
    } // end if
} // end isPrime

unsigned int reverseNum(unsigned int _origiNum)
{
    unsigned int uiLast = _origiNum / 1000;
    unsigned int uiTen = (_origiNum - 1000 * uiLast) / 100;
    unsigned int uiHundred = (_origiNum - 1000 * uiLast - 100 * uiTen) / 10;
    unsigned int uiThousand = _origiNum - 1000 * uiLast - 100 * uiTen - 10 * uiHundred;

    unsigned int uiNewNumber = 1000 * uiThousand + 100 * uiHundred + 10 * uiTen + uiLast; // new reversed number
    
    return uiNewNumber;
} // end reverseNum
