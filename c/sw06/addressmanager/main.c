/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on April 5, 2014, 9:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "address.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    char cmd;
    ui_help();
    do
    {
        while (!isalnum(cmd = getchar()));
        cmd = toupper(cmd);
        switch(cmd)
        {
            case 'N':
                ui_new();
                break;
            case 'L':
                ui_list();
                break;
            case 'D':
                ui_deleteall();
                break;
            case 'R':
                ui_read();
                break;
            case 'S':
                ui_save();
                break;
            case '1':
                ui_sortname();
                break;
            case '2':
                ui_sortstreet();
                break;
            case '3':
                ui_sortcity();
                break;
            case 'H':
                ui_help();
                break;
            case 'V':
                ui_version();
                break;
            default:
                break;
        }
    }
    while(cmd != 'Q');
    return (EXIT_SUCCESS);
}

