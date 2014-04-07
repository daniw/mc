/* 
 * File:   file.h
 * Author: daniw
 *
 * Created on April 6, 2014, 7:24 PM
 */

#ifndef FILE_H
#define	FILE_H

#include "address.h"


#ifdef	__cplusplus
extern "C" {
#endif

#define FILENAME "Address.txt"
#define FILEHEADER  "Firstname\t"\
                    "Name\t"\
                    "Street\t"\
                    "Number\t"\
                    "ZIP\t"\
                    "City\n"
#define FILECONTENT "%s\t%s\t%s\t%s\t%s\t%s\n"

void openfile(char* mode);
void writeheadfile(void);
void writedatafile(data_t data);
void readfile(void);
char readline(data_t* data);
void closefile();

#ifdef	__cplusplus
}
#endif

#endif	/* FILE_H */

