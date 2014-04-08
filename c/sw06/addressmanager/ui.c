/* 
 * File:   ui.c
 * Author: daniw
 *
 * Created on April 5, 2014, 9:32 PM
 */

#include "ui.h"
#include "address.h"
#include "file.h"

/**
 * User interface to add a new address entry
 */
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

/**
 * User interface to list all addresses
 */
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

/**
 * User interface to delete all addresses
 */
void ui_deleteall(void)
{
    nodePtr_t n;
    
    printf("%s", DELETEALLTEXT);
    while((n = getfirst()) != NULL)
    {
        removenode(n);
    }
    printf("%s", COMPLETEDTEXT);
    
    return;
}

/**
 * User interface to read address data from a file
 */
void ui_read(void)
{
    printf("%s", READTEXT);
    openfile("r");
    readfile();
    closefile();
    printf("%s", COMPLETEDTEXT);
    
    return;
}

/**
 * User interface to save address data to a file
 */
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

/**
 * User interface to sort addresses by name
 */
void ui_sortname(void)
{
    printf("%s", SORTNAMETEXT);
    #ifdef SORTENUM
    sortaddress(getfirst(), NAME);
    #else
    sortaddress(getfirst(), getname);
    #endif
    printf("%s", COMPLETEDTEXT);
    
    return;
}

/**
 * User interface to sort addresses by street
 */
void ui_sortstreet(void)
{
    printf("%s", SORTSTREETTEXT);
    #ifdef SORTENUM
    sortaddress(getfirst(), STREET);
    #else
    sortaddress(getfirst(), getstreet);
    #endif
    printf("%s", COMPLETEDTEXT);
    
    return;
}

/**
 * User interface to sort addresses by city
 */
void ui_sortcity(void)
{
    printf("%s", SORTCITYTEXT);
    #ifdef SORTENUM
    sortaddress(getfirst(), CITY);
    #else
    sortaddress(getfirst(), getcity);
    #endif
    printf("%s", COMPLETEDTEXT);
    
    return;
}

/**
 * User interface to print a help text
 */
void ui_help(void)
{
    printf("%s", HELPTEXT);
    
    return;
}

/**
 * User interface to print version and licence info
 */
void ui_version(void)
{
    printf("%s", VERSIONTEXT);
    
    return;
}

/**
 * User interface to print one set of data
 * @param data data to print
 */
void ui_printdata(data_t data)
{
    printf("%s%s %s\n",   LISTNAMETEXT,   data.firstname, data.name);
    printf("%s%s %s\n",   LISTSTREETTEXT, data.street,    data.number);
    printf("%s%s %s\n\n", LISTCITYTEXT,   data.zip,       data.city);
    
    return;
}