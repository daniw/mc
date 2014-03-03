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
void fibonacci2(int n);

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
        fibonacci2(n);
    }
    return (0);
}

/**
 * Function to compute and print fibonacci sequence
 * @param n Number of elements to be processed
 */
void fibonacci(int n)
{
    unsigned long long fib[n];
    int i;
    
    fib[0] = 0;
    printf("%llu\n", fib[0]);
    if (n > 1)
    {
        fib[1] = 1;
        printf("%llu\n", fib[1]);
    }
    
    for (i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        printf("%llu\n", fib[i]);
    }
}

/**
 * Function to compute and print fibonacci sequence
 * This algorithm is optimized to use minimal memory
 * fib[0] and fib[1] are used alternating to save the actual and the previous 
 * number. 
 * @param n Number of elements to be processed
 */
void fibonacci2(int n)
{
    unsigned long long fib[2];
    int i;
    
    fib[0] = 0;
    fib[1] = 1;
    printf("%llu\n", fib[0]);
    if (n > 1)
    {
        printf("%llu\n", fib[1]);
    }
    
    for (i = 2; i < n; i++)
    {
        fib[i & 1] += fib[(i & 1) ^ 1];         //binary & replaces % 2
        printf("%llu\n", fib[i & 1]);             //same function but faster
    }
}
