/* 
 * File:   main.c
 * Author: Daniel
 *
 * Created on 19. März 2014, 16:51
 */

#include <stdio.h>
#include <stdlib.h> /* fuer atof() */

/* hier alle Konstanten */
#define MAXOP 100 /* max Laenge von Operand und/oder Operator */
/* weitere hier anfuegen */

void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);
/* weitere hier anfuegen */

char buf[BUFSIZE];
/* weitere hier anfuegen */
/* Taschenrechner in umgekehrter polnischer Notation - Beispiel S. 74 K&R */

int main() {
/* hier lokale Variablen definieren */
freopen("inputfile1.txt", "r", stdin);
//Oeffnet das File "inputfile.txt" in dem Pfad von main.c und nimmt das File als //Standard Eingabe anstelle Tastatur
while ((type = getop(s)) != EOF) {
/* hier ausprogrammieren */ }
fclose(stdin); // Schliesst die Standard-Eingabe stdin (das File von freopen)
return(0);}

/* push: f auf den Stack bringen */
void push(double f) {
/* hier ausprogrammieren */}

/*pop: Wert von Stack holen und liefern */
double pop(void) {
/* hier ausprogrammieren */}

/*getop: naechsten Operator und /oder numerischen Operanden holen */
int getop(char s[]){
/* hier ausprogrammieren */}

/* Zeichen holen mit Buffer */
int getch(void) {
/* hier ausprogrammieren */}

/* Zeichen wieder zurueckstellen wenn zuviel geholt */
void ungetch(int c){
/* hier ausprogrammieren */}
