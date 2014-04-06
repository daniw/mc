/* 
 * File:   ui.h
 * Author: daniw
 *
 * Created on April 5, 2014, 9:32 PM
 */

#ifndef UI_H
#define	UI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "address.h"
    
#define ADDFIRSTNAMETEXT    "Firstname: "
#define ADDNAMETEXT         "Name:      "
#define ADDSTREETTEXT       "Street:    "
#define ADDNUMBERTEXT       "Street no: "
#define ADDZIPTEXT          "ZIP:       "
#define ADDCITYTEXT         "City:      "
#define LISTTEXT            "Here are all addresses listed\n"
#define READTEXT            "Reading from file...\n"
#define SAVETEXT            "Saving to file...\n"
#define SORTNAMETEXT        "Sorting for name...\n"
#define SORTSTREETTEXT      "Sorting for street...\n"
#define SORTCITYTEXT        "Sorting for city...\n"
#define HELPTEXT            "N --> New address\n"\
                            "L --> List addresses\n"\
                            "R --> Read addresses from file\n"\
                            "S --> Save addresses to file\n"\
                            "1 --> Sort list by name\n"\
                            "2 --> Sort list by street\n"\
                            "3 --> Sort list by city\n"\
                            "H --> Show this help text\n"\
                            "V --> Show version and licence info\n"\
                            "Q --> Quit\n\n"
#define VERSIONTEXT         "Developed by daniw\n"\
                            "Licenced under GPLv2\n"\
                            "Source Code available: \n"\
                            "https://github.com/daniw/mc/tree/master/c/sw06/addressmanager\n"
#define COMPLETEDTEXT       "Completed\n\n"
#define LISTNAMETEXT        "Name:   "
#define LISTSTREETTEXT      "Street: "
#define LISTCITYTEXT        "City:   "

void ui_new(void);
void ui_list(void);
void ui_read(void);
void ui_safe(void);
void ui_sortname(void);
void ui_sortstreet(void);
void ui_sortcity(void);
void ui_help(void);
void ui_version(void);
void ui_printdata(data_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */

