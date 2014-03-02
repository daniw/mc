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
#define MAXCHARS 100

/*
 * Function prototypes
 */
void reverse(char s[]);
int readLine(char s[], int limit);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    char s[MAXCHARS + 1];
    int number;
    
    do
    {
        printf("String I should reverse: ");
        number = readLine(s, MAXCHARS);
        //reverse(s);
        reversexor(s);
        printf("%s\n", s);
    }
    while (number > 1);
    return (0);
}

/**
 * Function to reverse a String
 * @author daniw
 * @param s String to be reversed
 */
void reverse(char s[])
{
    char t;
    int p1;
    int p2;
    for (p1 = 0, p2 = (int) strlen(s) - 1; p1 < p2; p1++, p2--)
    {
        t = s[p2];
        s[p2] = s[p1];
        s[p1] = t;
    }
    
}

/**
 * Function to reverse a String
 * The exchanging algorithm is based on exclusive or 
 * @author daniw
 * @param s String to be reversed
 */
void reversexor(char s[])
{
    int p1;
    int p2;
    for (p1 = 0, p2 = (int) strlen(s) - 1; p1 < p2; p1++, p2--)
    {
        s[p2] ^= s[p1];
        s[p1] ^= s[p2];
        s[p2] ^= s[p1];
    }
    
}

/**
 * Liest eine Zeile von maximal limit Zeichen ein.
 * Die Zeichen werden (inklusive Zeilenende-Zeichen) im übergebenen
 * Vektor s /0 terminiert abgelegt.
 * @param s Zeiger auf den Vektor zum Speichern der Eingabe
 * @param limit Maximale Grösse des Vektors
 * @return Anzahl eingelesene Zeichen
 */
int readLine(char s[], int limit)
{
    int i = 0;
    int c;
    c = getchar();              /* Buchstabe einlesen */
    while((c != EOF) &&         /* Ende File ... */
          (c != '\n') &&        /* oder Ende Zeile ... */
          (i < limit - 1))      /* oder Limite des Speichers? */
    {
        s[i] = c;
        i++;
        c = getchar();
    }
    if (c == '\n')
    {
        s[i] = '\n';            /* Zeilenumbruch anfügen! */
        i++;
    }
    s[i] = '\0';                /* Zeichenkette-Ende anfügen! */
    return i;                   /* Anzahl gelesene Zeichen zurückgeben */
}

