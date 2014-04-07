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

void readfile()
{
    data_t data;
    if(readline(&data) != EOF)
    {
        while(readline(&data) != EOF)
        {
            add(data);
        }
    }
    return;
}

char readline(data_t* data)
{
    data_t header;
    char c;
    char tmp[30];
    fields_t field = 0;
    unsigned int i = 0;
    
    while((c = fgetc(fp)) != EOF && c != '\n')
    {
        switch(c)
        {
            case '\t':
            case ',':
                tmp[i] = '\0';
                switch(field)
                {
                    case FIRSTNAME:
                        strcpy(data->firstname, tmp);
                        break;
                    case NAME:
                        strcpy(data->name, tmp);
                        break;
                    case STREET:
                        strcpy(data->street, tmp);
                        break;
                    case NUMBER:
                        strcpy(data->number, tmp);
                        break;
                    case ZIP:
                        strcpy(data->zip, tmp);
                        break;
                    case CITY:
                        strcpy(data->city, tmp);
                        break;
                }
                i = 0;
                field++;
                break;
            default:
                tmp[i] = c;
                i++;
                break;
        }
        strcpy(data->city, tmp);
    }
    return c;
}

void closefile()
{
    fclose(fp);
    return;
}

