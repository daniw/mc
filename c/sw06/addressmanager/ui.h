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
    
#define ADDFIRSTNAMETEXT    "Firstname: "
#define ADDNAMETEXT         "Name:      "
#define ADDSTREETTEXT       "Street:    "
#define ADDNUMBERTEXT       "Street n#: "
#define ADDZIPTEXT          "ZIP:       "
#define ADDCITYTEXT         "City:      "
#define LISTTEXT            "Here are all addresses listed\n"
#define READTEXT            "Reading file\n"
#define SAFETEXT            "Safing file\n"
#define SORTNAMETEXT        "Sorting for name\n"
#define SORTSTREETTEXT      "Sorting for street\n"
#define SORTCITYTEXT        "Sorting for city\n"
#define HELPTEXT            "Here comes the help text\n"
#define VERSIONTEXT         "Here comes the version text\n"
#define ASKTEXT             "Ask for parameter 1\n"

void ui_new(void);
void ui_list(void);
void ui_read(void);
void ui_safe(void);
void ui_sortname(void);
void ui_sortstreet(void);
void ui_sortcity(void);
void ui_help(void);
void ui_version(void);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */

