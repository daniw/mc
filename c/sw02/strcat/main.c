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

/*
 * Constants
 */

/*
 * Function prototypes
 */
void mystrcat(char s[], char t[]);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    char s[128];
    char t[128];
    
    while (1)
    {
        printf("String 1: ");
        scanf("%s", s);
        printf("String 2: ");
        scanf("%s", t);
        mystrcat(s, t);
        printf("%s\n\n", s);
    }
    
    return (0);
}

/**
 * Function to concatenate two strings
 * String t is added to String s
 * @param s First String
 * @param t Second String
 */
void mystrcat(char s[], char t[])
{
    int p1;
    int p2;
    
    p1 = 0;
    while (s[p1] != '\0')
    {
        p1++;
    }
    p2 = 0;
    while (t[p2] != '\0')
    {
        s[p1] = t[p2];
        p1++;
        p2++;
    }
    s[p1] = '\0';
}
