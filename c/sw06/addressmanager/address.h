/* 
 * File:   address.h
 * Author: daniw
 *
 * Created on April 6, 2014, 1:46 PM
 */

#ifndef ADDRESS_H
#define	ADDRESS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct data_
{
    char firstname[50];
    char name[50];
    char street[50];
    char number[10];
    char zip[10];
    char city[50];
} data_t;
//typedef struct data_
//{
//    char* firstname;
//    char* name;
//    char* street;
//    char* number;
//    char* zip;
//    char* city;
//} data_t;

typedef enum fields_
{
    FIRSTNAME,
    NAME,
    STREET,
    NUMBER,
    ZIP,
    CITY,
    END
} fields_t;

typedef struct node_* nodePtr_t;

typedef struct node_
{
    data_t data;
    nodePtr_t next;
    nodePtr_t prev;
} node_t;

void add(data_t data);
//data_t remove(nodePtr_t n);
nodePtr_t getfirst(void);
nodePtr_t getnext(nodePtr_t n);
nodePtr_t getprev(nodePtr_t n);
data_t getdata(nodePtr_t n);

#ifdef	__cplusplus
}
#endif

#endif	/* ADDRESS_H */

