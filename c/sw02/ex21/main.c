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
void reverse(char s[]);
int readLine(char s[], int limit);

/**
 * main
 * @author daniw
 */
int main(int argc, char** argv)
{
    
    return (0);
}

/**
 * @author daniw
 * @param s
 */
void reverse(char s[])
{
    
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

