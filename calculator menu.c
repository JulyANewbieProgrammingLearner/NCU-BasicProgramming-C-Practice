/*
menu:
1. add
2. substract
3. multiple
4. divide
5. end program
*/

#include <stdio.h>

// function prototype
void introduce(void); // introducing string
float addition(float a, float b); // def addition
float Subtraction(float c, float d); // def subtraction
float Multiplication(float p, float q); // def multiplication
float ensuredinominater(float z); // ensure dinominater not equal to 0
float Division(float m, float n); // def division

// start main
int main(void)
{
    // def and initialize
    unsigned int iFunctionNum = 0;
    float fAdd_num1 = 0;
    float fAdd_num2 = 0;
    float fSubtract_num1 = 0;
    float fSubtract_num2 = 0;
    float fMulti_num1 = 0;
    float fMulti_num2 = 0;
    float fDivi_num1 = 0;
    float fDivi_num2 = 0;

    introduce();

    printf("Please enter a number between 1 to 5 to determine the function you feel like operating: "); // prompt user to enter function num
    scanf("%d", &iFunctionNum); // read and store num

    // start do... while
    do
    {
        // start switch
        switch(iFunctionNum)
        {
            case 1:
                printf("Enter the first number: "); // prompt user to enter num1
                scanf("%f", &fAdd_num1); // read and store num1
                printf("Enter the second number: "); // prompt user to enter num2
                scanf("%f", &fAdd_num2); // read and store num2

                printf( "The value of addtion is %f.\n", addition(fAdd_num1, fAdd_num2) ); // result str
                    break;
            case 2:
                printf("Subtraction format: A - B\n");
                printf("Please enter the number A: "); // prompt user to enter num1
                scanf("%f", &fSubtract_num1); // read and store num1
                printf("Please enter the number B: "); // prompt user to enter num2
                scanf("%f", &fSubtract_num2); // read and store num2
                
                printf( "The value of the subtraction is %f.\n", Subtraction(fSubtract_num1, fSubtract_num2) ); // result str
                    break;
            case 3:
                printf("Multiplication format: A * B\n");
                printf("Please enter the number A: "); // prompt user to enter num1
                scanf("%f", &fMulti_num1); // read and store num1
                printf("Please enter the number B: "); // prompt user to enter num2
                scanf("%f", &fMulti_num2); // read and store num2
                
                printf( "The value of multiplication is %f\n", Multiplication(fMulti_num1, fMulti_num2) ); // result str
                    break;
            case 4:
                printf("Division format: A / B\n");
                printf("Please enter the number A: "); // prompt user to enter num1
                scanf("%f", &fDivi_num1); // read and store num1
                printf("Please enter the number B: "); // prompt user to enter num2
                scanf("%f", &fDivi_num2); // read and store num2

                fDivi_num2 = ensuredinominater(fDivi_num2); // make dinominater not equal to 0             
                printf( "The value of division is %f\n", Division(fDivi_num1, fDivi_num2) ); // result str  
                    break;
            case 5:
                    break;
            default:
                printf("There is no function which matched to No.%d\n", iFunctionNum);
                printf("Please enter a number between 1 to 5.\n");
                    break;
        } // end switch

        printf("Please enter a number between 1 to 5 to determine the function you feel like operating: "); // prompt user to enter function num
        scanf("%d", &iFunctionNum); // read and store num

    } while(iFunctionNum != 5); // end do... while

    printf("End program.\n"); // end str
    printf("Bye bye.\n"); // end str    
} // end main

void introduce(void)
{
    // start intro str
    printf("The program will have two numbers done simple calculation\n");
    printf("Enter 1 to run the addition function.\n");
    printf("Enter 2 to run the subtraction fuction.\n");
    printf("Enter 3 to run the multiplication function.\n");
    printf("Enter 4 to run the division function.\n");
    printf("Enter 5 to end the program.\n"); // end intro str
}
float addition(float _fAdd_num1, float _fAdd_num2)
{
    float fAdd_result = _fAdd_num1 + _fAdd_num2;

    return  fAdd_result;
}
float Subtraction(float _fSubtract_num1, float _fSubtract_num2)
{
    float fSubtract_result = _fSubtract_num1 - _fSubtract_num2;

    return fSubtract_result;
}
float Multiplication(float _fMulti_num1, float _fMulti_num2)
{
    float fMulti_result = _fMulti_num1 * _fMulti_num2;

    return fMulti_result;
}
float ensuredinominater(float _fDivi_num2)
{
    // start while_DomiChecking
    while(_fDivi_num2 == 0)
    {
        printf("Sorry! Your denominator is out of the domain.\n");
        printf("Please enter another valid number B: "); // prompt user enter another number
        scanf("%f", &_fDivi_num2); // read and store num
    } // end while_DomiChecking

    return _fDivi_num2;
}
float Division(float _fDivi_num1, float _fDivi_num2)
{
    float fDivi_result = _fDivi_num1 / _fDivi_num2;

    return fDivi_result;
}
