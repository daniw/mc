/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 23. März 2014, 14:20
 */

#include <stdio.h>
#include <stdlib.h>

#include "pressure.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    printf("running...\n");
    field_t field;
    field = createfield(3, 4);
    examplefield(field);
//    printfield(field);
    removefield(field);
    printf("Finished\n");
    return (EXIT_SUCCESS);
}

