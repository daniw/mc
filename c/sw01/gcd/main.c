/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 24. Februar 2014, 22:28
 */

/*
 * Includes
 */
#include <stdio.h>

/*
 * Constants
 */

/*
 * Function prototypes
 */
int gcd(int a, int b);

/*
 * @author daniw
 */
int main(int argc, char** argv)
{
    int a;
    int b;
    
    do
    {
        printf("Erste Zahl:  ");
        scanf("%d", &a);
        printf("Zweite Zahl: ");
        scanf("%d", &b);
        printf("ggT:         %d\n\n", gcd(a, b));
    }
    while (a != 0 && b != 0);
        
    return (0);
}

/*
 * Function for calculating the greatest common divisor of two numbers
 * @author daniw
 * @param a First number
 * @param b Second number
 * @return greatest common divisor
 */
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a < b)
        {
            int c;
            c = a;
            a = b; 
            b = c;
        }
        a -= b;
    }
    return (a);
}
