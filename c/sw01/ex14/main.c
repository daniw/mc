/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 23. Februar 2014, 17:17
 */

/*
 * Includes
 */
#include <stdio.h>

/*
 * Constants
 */
#define MINMENU 'A'
#define MAXMENU 'C'

/*
 * Function prototypes
 */
void printmenu();
void printsel1(char sel);
void printsel2(char sel);
void doA();
void doB();
void doC();

/*
 * @author daniw
 */
int main(int argc, char** argv)
{
    char sel;

    do
    {
        printmenu();
        while (!isalpha(sel = getchar()));
        sel = toupper(sel);
        printsel2(sel);
    }    
    while (sel != 'Q' && sel != 'q');
    return (0);
}

/*
 * Function to print the menu selection
 * @author daniw
 */
void printmenu()
{
    char men;
    for (men = MINMENU; men <= MAXMENU; men++)
    {
        printf("%c --> Select menu item %c \n", men, men);
    }
    printf("Q --> Exit \nEnter Selection: \n");
}

/*
 * Menu selection funktion. 
 * This function only returns some Text according to the selected menu. 
 * @author daniw
 * @param sel Selectec menu
 */
void printsel1(char sel)
{
    printf("\t\t%c%c%c\n", MINMENU, sel, MAXMENU);
    if (sel == 'Q')
    {
        printf("Exiting...\n");
    }
    else if (sel >= MINMENU && sel <= MAXMENU)
    {
        printf("Menu %c selected\n\n", sel);
    }
    else 
    {
        printf("Invalid Menu\n\n");
    }
}

/*
 * Menu selection funktion. 
 * This function calls a function according to the selected menu. 
 * @author daniw
 * @param sel Selectec menu
 */
void printsel2(char sel)
{
    switch(sel)
    {
        case 'A' :
            printf("Menu A selected\n\n");
            doA();
            break;
        case 'B' :
            printf("Menu B selected\n\n");
            doB();
            break;
        case 'C' :
            printf("Menu C selected\n\n");
            doC();
            break;
        case 'Q' :
            printf("Exiting...\n\n");
            break;
        default :
            printf("Invalid Menu\n\n");
            break;
        
    }
}

/*
 * Empty function as placeholder for actions performed in menu A
 * @author daniw
 */
void doA()
{
    return;
}

/*
 * Empty function as placeholder for actions performed in menu B
 * @author daniw
 */
void doB()
{
    return;
}

/*
 * Empty function as placeholder for actions performed in menu C
 * @author daniw
 */
void doC()
{
    return;
}
