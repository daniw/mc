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

#define SORTENUM
#ifndef SORTENUM
#define SORTFUNCTIONPOINTER
#endif

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

/**
 * Function to add a new address to the Linked List
 * @param data data to be added to the Linked List
 */
void add(data_t data);

/**
 * Function to remove an address from the Linked List
 * @param n Pointer to the node to be removed from the Linked List
 * @return data from the removed node
 */
data_t removenode(nodePtr_t n);

/**
 * Function to get the first node from the Linked List
 * @return Pointer to the first node in the Linked List
 */
nodePtr_t getfirst(void);

/**
 * Function to get the next node from the Linked List
 * @param n Pointer to the actual node in the Linked List
 * @return Pointer to the next node in the Linked List
 */
nodePtr_t getnext(nodePtr_t n);

/**
 * Function to get the previous node from the Linked List
 * @param n Pointer to the actual node in the Linked List
 * @return Pointer to the previous node in the Linked List
 */
nodePtr_t getprev(nodePtr_t n);

/**
 * Function to get the size of the Linkd List
 * @return size of the Linked List in number of data sets
 */
int getsize();

/**
 * Function to get an address from the Linked List
 * @param n Pointer to the requested address
 * @return address
 */
data_t getdata(nodePtr_t n);

/**
 * Function to get a specific field from an address
 * @param n Pointer to address
 * @param field field that has to be returned
 * @return Pointer to the value of the requested field
 */
char* getfield(nodePtr_t n, fields_t field);

/**
 * Function to get the firstname of an address
 * @param n Pointer to address
 * @return firstname
 */
char* getfirstname(nodePtr_t n);

/**
 * Function to get the name of an address
 * @param n Pointer to address
 * @return name
 */
char* getname(nodePtr_t n);

/**
 * Function to get the street of an address
 * @param n Pointer to address
 * @return street
 */
char* getstreet(nodePtr_t n);

/**
 * Function to get the number of an address
 * @param n Pointer to address
 * @return number
 */
char* getnumber(nodePtr_t n);

/**
 * Function to get the zip code of an address
 * @param n Pointer to address
 * @return zip code
 */
char* getzip(nodePtr_t n);

/**
 * Function to get the city of an address
 * @param n Pointer to address
 * @return city
 */
char* getcity(nodePtr_t n);

#ifdef SORTENUM
/**
 * Function to sort the Linked List
 * This function sorts according to the field given as enum
 * @param n Pointer to the first element
 * @param field field to sort for
 */
void sortaddress(nodePtr_t n, fields_t field);
#else
/**
 * Function to sort the Linked List
 * This function sorts accorting to the getter function given
 * @param n Pointer to the first element
 * @param getter Function pointer to the function to get the field to sort for
 */
void sortaddress(nodePtr_t n, char* (*getter)(nodePtr_t n));
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ADDRESS_H */

