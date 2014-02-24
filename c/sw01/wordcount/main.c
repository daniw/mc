/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 24. Februar 2014, 22:49
 */

/*
 * Includes
 */
#include <stdio.h>

/*
 * Constants
 */
#define FALSE 0
#define TRUE  1
/*
 * Function prototypes
 */

/*
 * Counts words in input stream
 * @author daniw
 */
int main(int argc, char** argv)
{
    char ch;
    unsigned int words;
    char space;
    
    do
    {
        ch = getchar();
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            space = TRUE;
        }
        else
        {
            if (space == TRUE)
            {
                words++;
            }
            space = FALSE;
        }
    }
    while (ch != EOF);
    printf("Number of Words: %d", words);
    
    return (0);
}

