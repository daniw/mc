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
 * Typedefinitions
 */
typedef enum Color_
{
    RED, 
    GREEN, 
    BLUE
} Color_t;

/*
 * Function prototypes
 */
char* colortostring(Color_t c);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    Color_t i;
    for (i = 0; i <= BLUE; i++)
    {
        printf("%s\n", colortostring(i));
    }
    return (0);
}

/**
 * Function to print the name of a enum variable from type Color_t
 * @param c 
 * @return 
 */
char* colortostring(Color_t c)
{
    switch(c)
    {
        case RED:
            return "RED";
            break;
        case GREEN:
            return "GREEN";
            break;
        case BLUE:
            return "BLUE";
            break;
        default:
            return("Not valid color");
            break;
    }
}
