// introduce
/*
three double values as the side of triangle
calculate and return the area
use this function: double calcTriangleArea(double sideA, double sideB, double sideC)
*/
#include <stdio.h>
#include <math.h>

// function prototype
double EnsureLengthPositive(double length_Input); // ensure length positive value
double BiggerNum(double a, double b); // find which is bigger
double SmallerNum(double a, double b); // find which is smaller
double FindMaximum(double a, double b, double c); // find which is maximum
double FindMinimum(double a, double b, double c); // find which is minimum
double FindMedian(double a, double b, double c); // find which is median
double calcTriangleArea(double a, double b, double c); // function of calculating the triangle area

// start main
int main(void)
{
    // declare variables
    double dSideA;
    double dSideB;
    double dSideC;

    printf("Please enter the first side of triangle: ");
    scanf("%lf", &dSideA);
    dSideA = EnsureLengthPositive(dSideA); // ensure SideA positve number

    printf("Please enter the second side of triangle: ");
    scanf("%lf", &dSideB);
    dSideB = EnsureLengthPositive(dSideB); // ensure SideB positve number

    printf("Please enter the third side of triangle: ");
    scanf("%lf", &dSideC);
    dSideC = EnsureLengthPositive(dSideC); // ensure SideC positve number

    double Maximum = FindMaximum(dSideA, dSideB, dSideC); // find maximum
    double Minimum = FindMinimum(dSideA, dSideB, dSideC); // find minimum
    double Median = FindMedian(dSideA, dSideB, dSideC); // find median

    if(Median + Minimum > Maximum) // start outer if
    {
        // start middle if
        if(Median == Minimum && Minimum == Maximum)
        {
            printf("This is an equilateral triangle ");
            printf("and the triangle area is %lf.\n", calcTriangleArea(Median, Minimum, Maximum));
        }
        else if(Median != Minimum && Minimum != Maximum && Maximum != Median)
        {
            // start inner if
            if(pow(Maximum, 2) == pow(Median, 2) + pow(Minimum, 2))
            {
                double dRightTriangleArea = Median * Minimum / 2;

                printf("This is a right triangle ");
                printf("and the triangle area is %lf.\n", dRightTriangleArea);
            }
            else
            {
                printf("This is normal triangle, which is other than right triangle, equilateral triangle, and isosceles triangle.\n");
                printf("And the triangle area is %lf.\n", calcTriangleArea(Median, Minimum, Maximum));
            } // end inner if
        }
        else
        {
            printf("This is an isosceles triangle ");
            printf("and the triangle area is %lf.\n", calcTriangleArea(Median, Minimum, Maximum));
        } // end midke if
    }
    else
    {
        printf("This is not a triangle.\n");
    } // end outer if
} // end main

// def function
double EnsureLengthPositive(double _dLength)
{
    while(_dLength <= 0)
    {
        printf("Please enter the length again: ");
        scanf("%lf", &_dLength);
    }

    return _dLength;
} // end EnsureLengthPositive

double BiggerNum(double _a, double _b)
{
    double bigger;
    if(_a > _b)
    {
        bigger = _a;
    }
    else
    {
        bigger = _b;
    }

    return bigger;
} // end BiggerNum

double SmallerNum(double _a, double _b)
{
    double smaller;

    if(_a < _b)
    {
        smaller = _a;
    }
    else
    {
        smaller = _b;
    }

    return smaller;
} // end SmallerNum

double FindMaximum(double _a, double _b, double _c)
{
    double LeftBigger = BiggerNum(_a,  _b);
    double RightBigger = BiggerNum(_b, _c);
    double Maximum = BiggerNum(LeftBigger, RightBigger);

    return Maximum;
} // end FindMaximum

double FindMinimum(double _a, double _b, double _c)
{
    double LeftSmaller = SmallerNum(_a, _b);
    double RightSmaller = SmallerNum(_b, _c);
    double Minimum = SmallerNum(LeftSmaller, RightSmaller);

    return Minimum;
} // end FindMinimum

double FindMedian(double _a, double _b, double _c)
{
    double Median;

    // start if
    if(FindMaximum(_a, _b, _c) > _a && _a > FindMinimum(_a, _b, _c))
    {
        Median = _a;
    }
    if(FindMaximum(_a, _b, _c) > _b && _b > FindMinimum(_a, _b, _c))
    {
        Median = _b;
    }
    if(FindMaximum(_a, _b, _c) > _c && _c > FindMinimum(_a, _b, _c))
    {
        Median = _c;
    } // end if

    return Median;
} // end FindMedian

double calcTriangleArea(double _a, double _b, double _c)
{
    double S_SideTotal = (_a + _b + _c) / 2;
    double Process = S_SideTotal * (S_SideTotal - _a) * (S_SideTotal - _b) * (S_SideTotal - _c);
    double Area_Triangle = pow(Process, 0.5);

    return Area_Triangle;
} // end calcTriangleArea
