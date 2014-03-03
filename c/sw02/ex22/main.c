/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 1. März 2014, 08:15
 */

/*
 * Includes
 */
#include <stdio.h>
#include <math.h>

/*
 * Constants
 */

/*
 * Function prototypes
 */
char* itoa(int i);
char* itoaneg(int i);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    int i;
    while (1)
    {
        printf("Number to convert: ");
        scanf("%d", &i);
        itoa(i);
        printf("%s\n", itoa(i));
        printf("%s\n", itoaneg(i));
    }
    
    return (0);
}

/**
 * Function to convert an integer number into a String
 * @author daniw
 * @param i integer value to be converted
 * @return String representation of given number
 */
char* itoa(int i)
{
    unsigned int digits = log10(i) + 1;
    char s[digits];
    int p;
    
    s[digits] = '\0';
    
    for (p = digits - 1; p >= 0; p--)
    {
        s[p] = (i % 10) + '0';
        i /= 10;
    }
    
    return s;
}

/**
 * Function to convert an integer number into a String
 * This function does also cover negative values
 * @author daniw
 * @param i integer value to be converted
 * @return String representation of given number
 */
char* itoaneg(int i)
{
    unsigned int digits = i >= 0 ? log10(i) + 1 : log10(abs(i)) + 2;
    char s[digits];
    int p;
    
    s[digits] = '\0';
    if (i < 0)
    {
        s[0] = '-';
    }
    p = digits - 1;
    i = abs(i);
    while (i > 0)
    {
        s[p] = (i % 10) + '0';
        i /= 10;
        p--;
    }
    
    return s;
}
