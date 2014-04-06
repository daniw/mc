#include "ui.h"

void ui_new(void)
{
    printf("%s", ADDFIRSTNAMETEXT);
    printf("%s", ADDNAMETEXT);
    printf("%s", ADDSTREETTEXT);
    printf("%s", ADDNUMBERTEXT);
    printf("%s", ADDZIPTEXT);
    printf("%s", ADDCITYTEXT);
    return;
}

void ui_list(void)
{
    printf("%s", LISTTEXT);
    return;
}

void ui_read(void)
{
    printf("%s", READTEXT);
    
    printf("%s", COMPLETEDTEXT);
    return;
}

void ui_save(void)
{
    printf("%s", SAVETEXT);
    
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

