#include <stdio.h>
#include <math.h>

// function prototype
unsigned int Bigger(unsigned int x, unsigned int y); // find the bigger number
unsigned int whichMax(unsigned int a, unsigned int b, unsigned int c); // find the maximum number
unsigned int Smaller(unsigned int m, unsigned int n); // find the smaller number
unsigned int whichMin(unsigned int a, unsigned int b, unsigned int c); // find the minimum number
unsigned int whichMedium(unsigned int _a, unsigned int _b, unsigned int _c); // find medium number
void isTriangle_different_Length(unsigned int a, unsigned int b, unsigned int c); // judge which triangle
void isTriangle_TwoEqualLength(unsigned int a, unsigned int b, unsigned int c); // judge is isosceles triangle
unsigned int Power(unsigned int base); // hold value

// start main
int main(void)
{
    printf("The program will help you judge the type of triangle.\n"); // intro str
    
    unsigned int uilength1 = 0; // def and initi variable
    unsigned int uilength2 = 0; // def and initi variable
    unsigned int uilength3 = 0; // def and initi variable

    printf("Please enter the length of side of triangle: "); // prompt user enter the num
    scanf("%d", &uilength1); // read and store the num
    scanf("%d", &uilength2); // read and store the num
    scanf("%d", &uilength3); // read and store the num
    
    while(uilength1 <= 0 || uilength2 <= 0 || uilength3 <= 0) // avoid the length of triangle to be 0
    {
        printf("Please enter the length of side of triangle again: "); // prompt user enter the num
        scanf("%d", &uilength1); // read and store the num
        scanf("%d", &uilength2); // read and store the num
        scanf("%d", &uilength3); // read and store the num
    } // end while

    // start if
    if(uilength1 == uilength2 && uilength2 == uilength3) // a = b = c ; judge triangle being equilateral triangle or not
    {
        printf("This is a equilateral triangle.\n");
    }
    else if(uilength1 != uilength2 && uilength2 != uilength3 && uilength1 != uilength3) // a != b && b != c ;three different length of triangle
    {
        isTriangle_different_Length(uilength1, uilength2, uilength3); // right triangle || triangle with different length ( other than right triangle ) || not even an triangle
    }
    else // a = b || b = c || c = a
    {
        isTriangle_TwoEqualLength(uilength1, uilength2, uilength3); // is isosceles triangle or not
    } // end if
} // end main

unsigned int Bigger(unsigned int _x, unsigned int _y)
{
    unsigned int uiBig;
    if(_x > _y)
    {
        uiBig = _x;
    }
    else
    {
        uiBig = _y;
    }
    return uiBig;
} // end Bigger

unsigned int whichMax(unsigned int _a, unsigned int _b, unsigned int _c)
{
    unsigned int uiLeftBig = Bigger(_a, _b);
    unsigned int uiRightBig = Bigger(_b, _c);
    unsigned int uiMax = Bigger(uiLeftBig, uiRightBig);
    
    return uiMax;
} // end whichMax

unsigned int Smaller(unsigned int _m, unsigned int _n)
{
    unsigned int uiSmall;
    if(_m > _n)
    {
        uiSmall = _n;
    }
    else
    {
        uiSmall = _m;
    }
    return uiSmall;
} // end Smaller

unsigned int whichMin(unsigned int _a, unsigned int _b, unsigned int _c)
{
    unsigned int uiLeftSmall = Smaller(_a, _b);
    unsigned int uiRightSmall = Smaller(_b, _c);
    unsigned int uiMin = Smaller(uiLeftSmall, uiRightSmall);

    return uiMin;
} // end whichMin

unsigned int whichMedium(unsigned int _a, unsigned int _b, unsigned int _c)
{
    unsigned int uiT;
    unsigned int uiTermiMedi;

    if(whichMax( _a, _b, _c) > _a && _a > whichMin(_a, _b, _c))
    {
        uiTermiMedi = _a;
    }
    else if(whichMax( _a, _b, _c) > _b && _b > whichMin(_a, _b, _c))
    {
        uiTermiMedi = _b;
    }
    else
    {
        uiTermiMedi = _c;
    }

    return uiTermiMedi;
} // end whichMedium

void isTriangle_different_Length(unsigned int _uilength1, unsigned int _uilength2, unsigned int _uilength3)
{
    unsigned int uiLength_Maximum = whichMax(_uilength1, _uilength2, _uilength3);
    unsigned int uiLength_Minimum =  whichMin(_uilength1, _uilength2, _uilength3);
    unsigned int uiLength_Medium = whichMedium(_uilength1, _uilength2, _uilength3);
    
    if(uiLength_Minimum + uiLength_Medium > uiLength_Maximum) // confirm it is an triangle
    {
        // start inner if
        if( Power(uiLength_Maximum) == Power(uiLength_Minimum) + Power(uiLength_Medium) ) // the condition of right triangle
        {
            printf("This is an right triangle.\n");
        }
        else // a triangle with all different length of sides 
        {
            printf("This is an triangle other than equilateral triangle, right triangle, and isosceles triangle.\n");
        } // end inner if
    }
    else // cannot form a triangle
    {
        printf("This is not a triangle.\n");
    }
} // end isTriangle_different_Length

void isTriangle_TwoEqualLength(unsigned int _uilength1, unsigned int _uilength2, unsigned int _uilength3)
{
    unsigned int uiTwoSide;
    unsigned int uiBottom;
    
    // start if 
    if(_uilength1 == _uilength2) // a = b
    {
        uiTwoSide = _uilength1;
        uiBottom = _uilength3;
    }
    else if(_uilength2 == _uilength3) // b = c
    {
        uiTwoSide = _uilength2;
        uiBottom = _uilength1;
    }
    else // c = a
    {
        uiTwoSide = _uilength1;
        uiBottom = _uilength2;
    } // end if

    // to check the triangle ; smallest + medium > biggest
    unsigned int Triangle_TwoEqualLength_Larger = Bigger(uiTwoSide, uiBottom);
    unsigned int Triangle_TwoEqualLength_smaller = Smaller(uiTwoSide, uiBottom);

    // start 2nd if
    if(Triangle_TwoEqualLength_smaller * 2 > Triangle_TwoEqualLength_Larger) // ensure the triangle exist && is an isosceles triangle
    {
        printf("This is an isosceles triangle.\n");
    }
    else // cannot even form a triangle
    {
        printf("This is not a triangle.\n");
    } // end 2nd if
} // end isTriangle_TwoEqualLength

unsigned int Power(unsigned int _uibase)
{
    unsigned int uipower_result = pow(_uibase, 2);

    return uipower_result;
} // end Power
