/* 
 * File:   weatherHandler.c
 * Author: Marco
 *
 * Created on 25. März 2014, 22:50
 * 
 * In diesem Programmteil werden alle Daten bezüglich des Wetters gehandhabt.
 * Dies beinhaltet zum einen die Initialisierung aber auch die Aenderung.
 */

//Importieren der Header-Datei mit allen Deklarationen und Bibliotheken
#include "head.h"
#include <string.h>
/*
 * Deklarieren und initialisiern der einzelnen Arrays mit den Daten für die
 * entsprechenden Tage. Es sind Arrays, welche Pointer auf die Strings enthalten.
 */

//char* montag = (char*) malloc(sizeof(char)*4);
void init(){
    char* montag[] = {"bewoelkt","14","50","11"};
    char* dienstag[] = {"bewoelkt","16","14"," 0"};
    char* mittwoch[] = {"sonnig","20","24"," 0"};
    char* donnerstag[] = {"leicht bewoelkt","21","12"," 0"};
    char* freitag[] = {"leicht bewoelkt","19","13"," 0"};
    char* samstag[] = {"bewoelkt","17","21","14"};
    char* sonntag[] = {"Regenschauer","13","25","25"};
}

/*
 * Methode, welche das Aendern der Daten erlaubt. FUNKTIONIERT NOCH NICHT!
 * @input  Ohne
 * @return Ohne
 */
void changeW(){
    char tmp1, tmp2;
    char tmp3[20];
    
    printf("Bitte gewuenschten Tag eingeben (1 - 7):\n");
    scanf("%s",&tmp1);
    printf("Bitte gewuenschtes Element eingeben (1 - 4):\n");
    scanf("%s",&tmp2);
    printf("Bitte geben Sie nun den neuen Inhalt ein:\n");
    scanf("%s",&tmp3);
    //strcpy((weather[tmp1-1][tmp2-1]),tmp3);
    weather[tmp1-1][tmp2-1] = &tmp3[0];
    printf("Inhalt wurde geaendert.\n");
    back();
}

