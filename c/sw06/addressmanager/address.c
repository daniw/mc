/* 
 * File:   address.c
 * Author: daniw
 *
 * Created on April 6, 2014, 1:46 PM
 */

#include "address.h"

static nodePtr_t head = NULL;
static nodePtr_t tail = NULL;

void add(data_t data)
{
    nodePtr_t n = (nodePtr_t) malloc(sizeof(node_t));
    
    if (head == NULL)
        head = n;
    n->next = NULL;
    n->prev = tail;
    if (tail != NULL)
        tail->next = n;
    tail = n;
    
    strcpy(n->data.firstname,   data.firstname);
    strcpy(n->data.name,        data.name);
    strcpy(n->data.street,      data.street);
    strcpy(n->data.number,      data.number);
    strcpy(n->data.zip,         data.zip);
    strcpy(n->data.city,        data.city);
}

/*
data_t remove(nodePtr_t n)
{
    data_t data = n->data;
    
    if(n->prev != NULL)
        n->prev.next = n->next;
    else
        head = n->next;
    
    if(n->next != NULL)
        n->next.prev = n->prev;
    else
        tail = n->prev;
    
    free(n);
    
    return data;
}
*/

nodePtr_t getfirst(void)
{
    return head;
}

nodePtr_t getnext(nodePtr_t n)
{
    return n->next;
}

nodePtr_t getprev(nodePtr_t n)
{
    return n->prev;
}
data_t getdata(nodePtr_t n)
{
    return n->data;
}
