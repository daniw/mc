/* 
 * File:   ui.c
 * Author: daniw
 *
 * Created on April 5, 2014, 9:32 PM
 */

#include "ui.h"
#include "address.h"
#include "file.h"

void ui_new(void)
{
    data_t data;
    
    printf("%s", ADDFIRSTNAMETEXT);
    scanf("%s", data.firstname);
    printf("%s", ADDNAMETEXT);
    scanf("%s", data.name);
    printf("%s", ADDSTREETTEXT);
    scanf("%s", data.street);
    printf("%s", ADDNUMBERTEXT);
    scanf("%s", data.number);
    printf("%s", ADDZIPTEXT);
    scanf("%s", data.zip);
    printf("%s", ADDCITYTEXT);
    scanf("%s", data.city);
    printf("%s", COMPLETEDTEXT);
    
    add(data);
    
    return;
}

void ui_list(void)
{
    nodePtr_t n;
    data_t data;
    
    printf("%s", LISTTEXT);
    n = getfirst();
    while(n != NULL)
    {
        data = getdata(n);
        ui_printdata(data);
        n = getnext(n);
    }
    return;
}

void ui_read(void)
{
    printf("%s", READTEXT);
    openfile("r");
    readfile();
    closefile();
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_save(void)
{
    nodePtr_t n;
    data_t data;
    
    printf("%s", SAVETEXT);
    
    openfile("w");
    writeheadfile();
    n = getfirst();
    while(n != NULL)
    {
        data = getdata(n);
        writedatafile(data);
        n = getnext(n);
    }
    closefile();
    
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_sortname(void)
{
    printf("%s", SORTNAMETEXT);
    
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_sortstreet(void)
{
    printf("%s", SORTSTREETTEXT);
    
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_sortcity(void)
{
    printf("%s", SORTCITYTEXT);
    
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_help(void)
{
    printf("%s", HELPTEXT);
    return;
}

void ui_version(void)
{
    printf("%s", VERSIONTEXT);
    return;
}

void ui_printdata(data_t data)
{
    printf("%s%s %s\n",   LISTNAMETEXT,   data.firstname, data.name);
    printf("%s%s %s\n",   LISTSTREETTEXT, data.street,    data.number);
    printf("%s%s %s\n\n", LISTCITYTEXT,   data.zip,       data.city);
    return;
}