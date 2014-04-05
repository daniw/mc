/* 
 * File:   head.h
 * Author: Marco
 *
 * Created on 25. März 2014, 22:34
 * 
 * Im vorliegenden Header-File sind alle Methoden deklariert, damit der Pre-Compiler
 * diese Informationen hat und eine sauberes compilieren ermöglicht wird.
 * Weiter sind Variablen oder Konstanten, welche im ganzen Programm verwendet
 * werden hier deklariert.
 * Das Selbe gilt für Bibliotheken, welche im ganzen Programm Anwendung finden.
 */

#ifndef HEAD_H
#define	HEAD_H

//Bibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Methodendeklarationen
void startText();
void menu1();
void back();
int read();
void print(int day);
void choose(char* t);
void changeW();
void clears();

//Typedef boolean
enum boolean {FALSE = 0, TRUE};

//Allg- Deklaration
char text;
char text2;
int quit;

//Statisches Array, welche die Tage Speichert
static char* days[] = {
    "Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Samstag","Sonntag"};

//Deklaration der unterschiedlichen Arrays, in welchen dann die Wetterdaten
//eingetragen werden
char* montag[4];
char* dienstag[4];
char* mittwoch[4];
char* donnerstag[4];
char* freitag[4];
char* samstag[4];
char* sonntag[4];

//Deklaration des zweidimensionalen Arrays, auf welches für die Wetterinformationen
//zugegriffen werden kann von überall im Programm.
static char** weather[] = {
    montag,dienstag,mittwoch,donnerstag,freitag,samstag,sonntag};

#endif	/* HEAD_H */

