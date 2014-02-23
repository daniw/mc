/* 
 * File:   main.c
 * Author: Daniel
 *
 * Created on 23. Februar 2014, 17:17
 */

#include <stdio.h>
#define MAXMENU  'C'

/*
 * 
 */
void printmenu()
{
    char men;
    for (men = 'A'; men <= MAXMENU; men++)
    {
        printf("%c --> Select menu item %c \n", men, men);
    }
    printf("Q --> Exit \nEnter Selection: \n");
}

/*
 * 
 */
int main(int argc, char** argv)
{
    do
    {
        printmenu();
    }    while ();
    return (0);
}

