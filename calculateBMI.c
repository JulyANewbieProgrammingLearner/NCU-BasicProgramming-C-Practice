/*
work flow:
1. Menu (n != 1)
2. iWeight in kg
3. iHeight in cm
4. fBmi store the value of BMI
5. print the result
*/
#include <stdio.h>
#include <math.h>

// function prototype
int defWeight(void); // def the value of weight
int defHeight(void); // def the value of height

// start main
int main(void)
{
    int  iFuncNum = 0;

    do
    {
        printf("This program will calculate the value of BMI.\n");
        int iWeight = defWeight();
        int iHeight = defHeight();
        float fHold = (float)iHeight / 100;
        float fBMI = (float)iWeight / pow(fHold, 2);
        printf("The value of BMI is %.2f\n", fBMI);

        printf("Do you want to leave the program (enter 1 to exit) : ");
        scanf("%d", &iFuncNum);
    } while (iFuncNum != 1);
    
    printf("Goodbye.\n");
} // end main

// def function
int defWeight(void)
{
    int iWeight = 0;

    do
    {
        printf("Enter the weight in kilogram: ");
        scanf("%d", &iWeight);

        if(iWeight <= 0)
        {
            printf("Invalid weight...\n");
        } // end if
    } while (iWeight <= 0);
    
    return iWeight;
} // end defWeight

int defHeight(void)
{
    int iHeight = 0;
    do
    {
        printf("Enter height in centimeter: ");
        scanf("%d", &iHeight);

        if(iHeight <= 0)
        {
            printf("Invalid height...\n");
        } // end if
    } while (iHeight <= 0);

    return iHeight;
} // end defHeight

