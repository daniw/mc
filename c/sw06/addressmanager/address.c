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

data_t removenode(nodePtr_t n)
{
    data_t data = n->data;
    
    if(n->prev != NULL)
        n->prev->next = n->next;
    else
        head = n->next;
    
    if(n->next != NULL)
        n->next->prev = n->prev;
    else
        tail = n->prev;
    
    free(n);
    
    return data;
}

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

int getsize()
{
    nodePtr_t n = getfirst();
    int i = 0;
    while(n != NULL)
    {
        n = getnext(n);
        i++;
    }
    return i;
}

data_t getdata(nodePtr_t n)
{
    return n->data;
}

char* getfield(nodePtr_t n, fields_t field)
{
    switch(field)
    {
        case FIRSTNAME:
            return n->data.firstname;
            break;
        case NAME:
            return n->data.name;
            break;
        case STREET:
            return n->data.street;
            break;
        case NUMBER:
            return n->data.number;
            break;
        case ZIP:
            return n->data.zip;
            break;
        case CITY:
            return n->data.city;
            break;
        default:
            return;
            break;
    }
}

char* getfirstname(nodePtr_t n)
{
    return n->data.firstname;
}

char* getname(nodePtr_t n)
{
    return n->data.name;
}

char* getstreet(nodePtr_t n)
{
    return n->data.street;
}

char* getnumber(nodePtr_t n)
{
    return n->data.number;
}

char* getzip(nodePtr_t n)
{
    return n->data.zip;
}

char* getcity(nodePtr_t n)
{
    return n->data.city;
}

#ifdef SORTENUM
void sortaddress(nodePtr_t n, fields_t field)
{
    int s = getsize();
    int i = 0;
    int j = 0;
    nodePtr_t t = getfirst();
    nodePtr_t* a = (nodePtr_t) malloc(s * sizeof(nodePtr_t));
    
    // Preparing array to sort
    for(i = 0; i < s; i++)
    {
        a[i] = t;
        t = getnext(t);
    }
    
    // Sorting the prepared array
    for(i = 0; i < (s); i++)
    {
        for(j = 0; j < (s - i - 1); j++)
        {
            if(strcmp(getfield(a[j], field), getfield(a[j+1], field)))
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    
    // Order data according to sorted array
    head = a[0];
    tail = a[s-1];
    a[0]->prev = NULL;
    a[0]->next = a[1];
    a[s-1]->next = NULL;
    a[s-1]->prev = a[s-2];
    for(i = 1; i < (s - 1); i++)
    {
        a[i]->next = a[i+1];
        a[i]->prev = a[i-1];
    }

    return;
}
#else
void sortaddress(nodePtr_t n, char* (*getter)(nodePtr_t n))
{
    int s = getsize();
    int i = 0;
    int j = 0;
    nodePtr_t t = getfirst();
    nodePtr_t* a = (nodePtr_t) malloc(s * sizeof(nodePtr_t));
    
    // Preparing array to sort
    for(i = 0; i < s; i++)
    {
        a[i] = t;
        t = getnext(t);
    }
    
    // Sorting the prepared array
    for(i = 0; i < (s); i++)
    {
        for(j = 0; j < (s - i - 1); j++)
        {
            if(strcmp(getter(a[j]), getter(a[j+1])))
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    
    // Order data according to sorted array
    head = a[0];
    tail = a[s-1];
    a[0]->prev = NULL;
    a[0]->next = a[1];
    a[s-1]->next = NULL;
    a[s-1]->prev = a[s-2];
    for(i = 1; i < (s - 1); i++)
    {
        a[i]->next = a[i+1];
        a[i]->prev = a[i-1];
    }

    return;
}
#endif
