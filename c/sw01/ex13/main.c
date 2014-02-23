/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 23. Februar 2014, 16:37
 */

#include <stdio.h>

/*
 * Funktion um die binäre Repräsentation einer Zahl auszugeben
 * @author daniw
 * @param wert Zahl, von welcher die binäre Repräsentation ausgegeben wird. 
 */
void printbin(int wert)
{
    unsigned int mask;

    mask = (1 << (sizeof (wert) * 8 - 1));
    for (mask = (1 << (sizeof (wert) * 8 - 1)); mask >= 1; mask = mask >> 1)
    {
        putchar((wert & mask) > 0 ? '1' : '0');
    }

    return;
}

/*
 * @author daniw
 */
int main(int argc, char** argv)
{
    int wert;

    printf("Wert als Integer (auch negativ): ");
    scanf("%d", &wert);

    printbin(wert);

    return (0);
}

