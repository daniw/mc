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
#define DELETEALLTEXT       "Deleting all addresses..."
#define READTEXT            "Reading from file...\n"
#define SAVETEXT            "Saving to file...\n"
#define SORTNAMETEXT        "Sorting for name...\n"
#define SORTSTREETTEXT      "Sorting for street...\n"
#define SORTCITYTEXT        "Sorting for city...\n"
#define HELPTEXT            "N --> New address\n"\
                            "L --> List addresses\n"\
                            "D --> Delete all addresses\n"\
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

/**
 * User interface to add a new address entry
 */
void ui_new(void);

/**
 * User interface to list all addresses
 */
void ui_list(void);

/**
 * User interface to delete all addresses
 */
void ui_deleteall(void);

/**
 * User interface to read address data from a file
 */
void ui_read(void);

/**
 * User interface to save address data to a file
 */
void ui_save(void);

/**
 * User interface to sort addresses by name
 */
void ui_sortname(void);

/**
 * User interface to sort addresses by street
 */
void ui_sortstreet(void);

/**
 * User interface to sort addresses by city
 */
void ui_sortcity(void);

/**
 * User interface to print a help text
 */
void ui_help(void);

/**
 * User interface to print version and licence info
 */
void ui_version(void);

/**
 * User interface to print one set of data
 * @param data data to print
 */
void ui_printdata(data_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */

