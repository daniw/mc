/* 
 * File:   file.c
 * Author: daniw
 *
 * Created on April 6, 2014, 7:24 PM
 */

#include "file.h"

//static char* file;// = "Address.txt";
static FILE* fp;

void openfile(char* mode)
{
    fp = fopen(FILENAME, mode);
    return;
}

void writeheadfile(void)
{
    fprintf(fp, "%s", FILEHEADER);
    return;
}

void writedatafile(data_t data)
{
    fprintf(fp, FILECONTENT, data.firstname, 
                             data.name, 
                             data.street, 
                             data.number, 
                             data.zip, 
                             data.street);
    return;
}

void closefile()
{
    fclose(fp);
    return;
}

