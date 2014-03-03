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
void fibonacci(int n);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    int n = 1;
    
    while(n > 0)
    {
        
        printf("Anzahl Fibonacci Zahlen: ");
        scanf("%d", &n);
        fibonacci(n);
    }
    return (0);
}

/**
 * Function to compute and print fibonacci sequence
 * @param n Number of elements to be processed
 */
void fibonacci(int n)
{
    unsigned int fib[n];
    int i;
    
    fib[0] = 0;
    printf("%u\n", fib[0]);
    if (n > 1)
    {
        fib[1] = 1;
        printf("%u\n", fib[1]);
    }
    
    for (i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        printf("%u\n", fib[i]);
    }
}
