/* 
 * File:   main.c
 * Author: daniw
 *
 * Created on 23. Februar 2014, 18:21
 */

/*
 * Includes
 */
#include <stdio.h>

/*
 * Constants
 */
#define TEMPFACTOR      5./9
#define TEMPOFFSET      32
#define MINTEMP         0
#define MAXTEMP         210
#define TEMPSTEP        15

/*
 * Function prototypes
 */
float fahrtocels(float temp);
float celstofahr(float temp);

/*
 * main function
 * @author daniw
 */
int main(int argc, char** argv)
{
    int temp;
    
    for (temp = MINTEMP; temp <= MAXTEMP; temp += TEMPSTEP)
    {
        printf("%3d\t%10.5f\n", temp, fahrtocels(temp));
    }
    
    return (0);
}

/*
 * Funktion zur Umrechnung eines Temperaturwertes von Grad Fahrenheit in Grad 
 * Celsius. 
 * °C = (5 / 9) * (°F - 32)
 * @author daniw
 * @param temp Temperatur in Grad Fahrenheit
 * @return temp Temperatur in Grad Celsius
 */
float fahrtocels(float temp)
{
    return (TEMPFACTOR * (temp - TEMPOFFSET));
}

/*
 * Funktion zur Umrechnung eines Temperaturwertes von Grad Fahrenheit in Grad 
 * Celsius. 
 * °C = (5 / 9) * (°F - 32)
 * @author daniw
 * @param temp Temperatur in Grad Fahrenheit
 * @return temp Temperatur in Grad Celsius
 */
float celstofahr(float temp)
{
    return ((temp / TEMPFACTOR) + TEMPOFFSET);
}

