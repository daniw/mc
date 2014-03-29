/* 
 * File:   main.c
 * Author: daniw (Original Source from Marco Bürgi)
 *
 * Created on March 29, 2014, 12:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

//Importieren der Header-Datei mit allen Deklarationen und Bibliotheken
#include "head.h"

/*
 * Mainmethode des Programmes. Beim Aufruf wird die main Methode als erstes aufgerufen.
 * @input  Ohne
 * @return Es wird eine 1 zurückgegeben, wenn die Ausfuehrung erfolgreich war, sonst 0.
 */
int main() {
  
    do{
        clears();
        quit = TRUE;
        startText();
        menu1();
        choose(read());
    }while(!quit);
    
    return (EXIT_SUCCESS);
}
