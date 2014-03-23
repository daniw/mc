/* 
 * File:   pressure.c
 * Author: daniw
 *
 * Created on 23. März 2014, 14:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pressure.h"


/**
 * Function to create an uninitialized measurement field
 * @param rows    number of rows
 * @param columns number of columns
 * @return        struct with pointer to measurements, number of rosw, number of columns
 */
field_t createfield(unsigned int rows, unsigned int columns)
{
    
}

/**
 * Function to fill the field with one single value and prefix
 * @param field     field to be filled
 * @param value     value to be filled in each measurement in field
 * @param prefix    prefex to be filled in each measurement in field
 */
void fillfield(field_t field, float value, meas_prefix_t prefix)
{
    
}

/**
 * Function to fill the field with faked values and prefixes
 * Used to simulate an actual measurement
 * The measurements are filled with random values and prefixes
 * @param field     field to be filled with random measurements
 */
void fakefield(field_t field)
{
    
}

/**
 * Function to get one measurement from a field
 * @param row       row in field, from where the measurement is read
 * @param column    column in field, from where the measurement is read
 * @return          measurement
 */
measurement_t getmeasurement(unsigned int row, unsigned int column)
{
    
}

/**
 * Function to print all the measurements in a field
 * @param field     field to be printed
 */
void printfield(field_t field)
{
    
}

/**
 * Function to print one single measurement
 * @param measurement   measurement to be printed
 */
void printmeasurement(measurement_t measurement)
{
    
}
