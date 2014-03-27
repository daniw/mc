/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 23. März 2014, 14:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "pressure.h"

//#define SPEEDTEST   1
//#define SPEEDTEST   2
#define SPEEDVALUE1 10000
#define SPEEDVALUE2 40000
//#define SPEEDVALUE1 40000000
//#define SPEEDVALUE2 10
//#define SPEEDVALUE1 10
//#define SPEEDVALUE2 40000000

/*
 * 
 */
int main(int argc, char** argv)
{
    printf("running...\n");
    field_t field;
    #ifndef SPEEDTEST
//        field = createfield(3, 4);
        field = createfield2(3, 4);
        examplefield(field);
        printfield(field);
//        removefield(field);
        removefield2(field);
    #else
    #if SPEEDTEST == 1
        field = createfield(SPEEDVALUE1, SPEEDVALUE2);
        removefield(field);
    #endif
    #if SPEEDTEST == 2
        field = createfield2(SPEEDVALUE1, SPEEDVALUE2);
        removefield2(field);
    #endif
    #endif      
    printf("Finished\n");
    printf("%d",  sizeof(measurement_t));
    return (EXIT_SUCCESS);
}
