/*
 * File:   textHandler.c
 * Author: Marco, daniw
 *
 * Created on 25. März 2014, 22:25
 * 
 * In diesem Bereich des Programmes werden alle verwendeten Texte gehandhabt.
 * Die sind Texte, welche zur Benutzerführung verwendet werden und die 
 * Befehle zur Ausführung beinhalten.
 */

//Importieren der Header-Datei mit allen Deklarationen und Bibliotheken
#include "head.h"

/*
 * Methode, welche die Titelzeile des Programm ausgibt.
 */
void startText(){
    printf("-----------------------------------------------------------------\n"
           "Wettervorhersage - DAS Wetterprogramm schlechthin!\n"
           "-----------------------------------------------------------------\n\n");
}

/*
 * Methode, welche die Menufuehrung fuer den Anwender zur verfuegung stellt.
 * Diese Befehle stellen die grundlegende Auswahl und Funktion fuer den Anwender dar.
 */
void menu1(){
    printf("Für welchen Tag möchten Sie die genauen Wetterdaten erhalten?\n\n"
           "Montag         > 1\n"
           "Dienstag       > 2\n"
           "Mittwoch       > 3\n"
           "Donnerstag     > 4\n"
           "Freitag        > 5\n"
           "Samstag        > 6\n"
           "Sonntag        > 7\n\n"
           "DAT bearbeiten > 8\n\n"
           "PRG beenden    > 9\n\n");
}

/*
 * Methode löscht den aktuellen Bildschirm, laedt die Titelzeile neu und bietet
 * eine weitere menuwahl dem Benutzer an. Dieser Teil wird im Bereich des editierens
 * der Wetterdaten verwendet.
 */
void menu2(){
    clears();
    startText();
    printf("Menu um die Wetterdaten zu verändern.\n\n"
           "Fuer den Tag bitte die gewünschte Nummer 1 - 7 "
           "für die Tage Montag - Sonntag\n"
           "und für das gewünschte Element\n"
           "Vorhersage, Temperatur, Windgeschw. oder Regenmenge 1 - 4\n\n");
}

/*
 * Diese Methode gibt einen Text aus, welche auf das zurueckspringen ins Hauptmenu
 * verweisst. 
 * In der Methode wird ebenfalls direkt die Abfrage nach der Eingabe des Benutzers
 * abgewartet und bei korrekter Eingabe die Variablen für ein sauberes Weiterkommen 
 * verändert.
 * Schlussendlich wird der aktuelle Bildschirminhalt gelöscht.
 */
void back(){
    char input;
    printf("Um wieder ins Hauptmenu zurueckzukehren "
           "bitte mit der Eingabe von B bestaetigen.");
    do {
        scanf("%s", &input);
    } while (toupper(input) != 'B');
    quit = FALSE;
    clears();
}

/*
 * Methode dient zum loeschen des aktuell auf dem Bildschirm angezeigten Inhaltes.
 */
void clears(){
    printf("\033[2J");
}

/*
 * Mit dieser Methode wird eine Eingabe im Eingabefeld aufgenommen und abgespeichert.
 * Die eingelesenen Werte werden als integer Wert angenommen.
 * @input  Ohne
 * @return Adresse des char Arrays des Textes.
 */
int read(){
    int text;
    scanf("%d",&text);
    return text;
}

/*
 * Mit dieser Methode wird eine Eingabe im Eingabefeld aufgenommen und abgespeichert.
 * Die eingelesenen Werte werden als Zeichenketten angenommen.
 * @input  Ohne
 * @return Adresse des char Arrays des Textes.
 */
char* read2(){
    scanf("%s",&text2);
    return &text2;
}

/*
 * Methode dient zur Ausgabe der Wetterdaten auf dem Bildschirm
 * Vorab wird der Bildschirm geloescht und die Startzeile wieder geladen.
 * @input  integer Wert von 1 - 7 für die Tage Montag bis Sonntag
 * @return Ohne
 */
void print(int day){
    clears();
    startText();
    printf("\033[34m\033[1m%s:\033[0m\n\n", days[day]);
    printf("Vorhersage :\t%s\n",weather[day][0]);
    printf("Temperatur :\t%s °C\n",weather[day][1]);
    printf("Windgeschw.:\t%s km/h\n",weather[day][2]);
    printf("Regenmenge :\t%s mm\n\n",weather[day][3]);
}

/*
 * Methode zum auswählen der gewuenschten Aktion, abhaengig von der Eingabe des 
 * Benutzers. 
 * @input  Es wird ein Pointer auf einen char verlangt.
 * @return Ohne
 */
void choose(char* t){
    switch(*t){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            print(*t-1);
            back();
            break;
        case 8:
            menu2();
            changeW();
            break;
        case 9:
            quit = TRUE;
            break;
        default:
            printf("ERROR: Undefinierte Eingabe: %d\n\n", *t);
            quit = FALSE;
            break;
    }
}