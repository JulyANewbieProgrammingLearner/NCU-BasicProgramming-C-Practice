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
    printf("The program will help you judge the type of triangle.\n");
    
    unsigned int uilength1 = 0;
    unsigned int uilength2 = 0;
    unsigned int uilength3 = 0;

    printf("Please enter the length of side of triangle: ");
    scanf("%d", &uilength1);
    scanf("%d", &uilength2);
    scanf("%d", &uilength3);
    
    while(uilength1 <= 0 || uilength2 <= 0 || uilength3 <= 0)
    {
        printf("Please enter the length of side of triangle again: ");
        scanf("%d", &uilength1);
        scanf("%d", &uilength2);
        scanf("%d", &uilength3);
    } // end while

    if(uilength1 == uilength2 && uilength2 == uilength3)
    {
        printf("This is a equilateral triangle.\n");
    }
    else if(uilength1 != uilength2 && uilength2 != uilength3 && uilength1 != uilength3)
    {
        isTriangle_different_Length(uilength1, uilength2, uilength3);
    }
    else
    {
        isTriangle_TwoEqualLength(uilength1, uilength2, uilength3);
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
    
    if(uiLength_Minimum + uiLength_Medium > uiLength_Maximum)
    {
        // start inner if
        if( Power(uiLength_Maximum) == Power(uiLength_Minimum) + Power(uiLength_Medium) )
        {
            printf("This is an right triangle.\n");
        }
        else
        {
            printf("This is an triangle other than equilateral triangle, right triangle, and isosceles triangle.\n");
        } // end inner if
    }
    else
    {
        printf("This is not a triangle.\n");
    }
} // end isTriangle_different_Length

void isTriangle_TwoEqualLength(unsigned int _uilength1, unsigned int _uilength2, unsigned int _uilength3)
{
    unsigned int uiTwoSide;
    unsigned int uiBottom;
    // start if 
    if(_uilength1 == _uilength2)
    {
        uiTwoSide = _uilength1;
        uiBottom = _uilength3;
    }
    else if(_uilength2 == _uilength3)
    {
        uiTwoSide = _uilength2;
        uiBottom = _uilength1;
    }
    else
    {
        uiTwoSide = _uilength1;
        uiBottom = _uilength2;
    } // end if

    unsigned int Triangle_TwoEqualLength_Larger = Bigger(uiTwoSide, uiBottom);
    unsigned int Triangle_TwoEqualLength_smaller = Smaller(uiTwoSide, uiBottom);

    // start 2nd if
    if(Triangle_TwoEqualLength_smaller * 2 > Triangle_TwoEqualLength_Larger)
    {
        printf("This is an isosceles triangle.\n");
    }
    else
    {
        printf("This is not a triangle.\n");
    } // end 2nd if
} // end isTriangle_TwoEqualLength

unsigned int Power(unsigned int _uibase)
{
    unsigned int uipower_result = pow(_uibase, 2);

    return uipower_result;
} // end Power
