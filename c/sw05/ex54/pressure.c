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
    field_t field;
    field.rows = rows;
    field.columns = columns;
    field.measurement = (measurement_t**) malloc(rows * sizeof(measurement_t*));
    unsigned int i;
    for (i = 0; i < rows; i++)
    {
        field.measurement[i] = (measurement_t*) malloc(columns * sizeof(measurement_t));
    }
    return field;
}

/**
 * Function to fill the field with one single value and prefix
 * @param field     field to be filled
 * @param value     value to be filled in each measurement in field
 * @param prefix    prefex to be filled in each measurement in field
 */
void fillfield(field_t field, float value, meas_prefix_t prefix)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < field.rows; i++)
    {
        for (j = 0; i < field.columns; j++)
        {
            field.measurement[i][j].value = value;
            field.measurement[i][j].prefix = prefix;
        }
    }
}

/**
 * Function to fill the field with faked values and prefixes
 * Used to simulate an actual measurement
 * The measurements are filled with random values and prefixes
 * @param field     field to be filled with random measurements
 */
void simfield(field_t field)
{
    unsigned int i;
    unsigned int j;
    //initialise random generator with current time
    srand(time(NULL));
    for (i = 0; i < field.rows; i++)
    {
        for (j = 0; j < field.columns; j++)
        {
            field.measurement[i][j].value = (float)(rand()%(VALUEMAX*VALUEPREC))/VALUEPREC;
            field.measurement[i][j].prefix = (meas_prefix_t) (rand()%LAST);
        }
    }
}

/**
 * Function to fill the field with values and prefixes as in example
 * @param field     field to be filled with example measurements
 */
void examplefield(field_t field)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < field.rows; i++)
    {
        for (j = 0; j < field.columns; j++)
        {
            field.measurement[i][j].value = i + 0.1 * j;
            field.measurement[i][j].prefix = KILO;
        }
    }
}

/**
 * Function to get one measurement from a field
 * @param row       row in field, from where the measurement is read
 * @param column    column in field, from where the measurement is read
 * @return          measurement
 */
measurement_t getmeasurement(field_t field, unsigned int row, unsigned int column)
{
    if ((row < field.rows) && (column < field.columns))
    {
        return field.measurement[row][column];
    }
    else
    {
        printf("ERROR: row or column exceed field range\n");
    }
}

/**
 * Function to set one measurement in a field
 * @param field         field in which the measurement is set
 * @param row           row in field, in which the measurement is set
 * @param column        column in field, in which the measurement is set
 * @param measurement   measurement to be copied to field. 
 */
void setmeasurement(field_t field, unsigned int row, unsigned int column, measurement_t measurement)
{
    if ((row < field.rows) && (column < field.columns))
    {
        field.measurement[row][column] = measurement;
    }
    else
    {
        printf("ERROR: row or column exceed field range\n");
    }
}

/**
 * Function to print all the measurements in a field
 * @param field     field to be printed
 */
void printfield(field_t field)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < field.rows; i++)
    {
        for (j = 0; j < field.columns ;j++)
        {
            printmeasurement(field.measurement[i][j]);
        }
        putchar('\n');
    }
}

/**
 * Function to print one single measurement
 * @param measurement   measurement to be printed
 */
void printmeasurement(measurement_t measurement)
{
    printf("%7.3f %s ", measurement.value, prefixtostring(measurement.prefix));
}

/**
 * Function that returns a string according to a prefix given
 * @param prefix    prefix to be turned to a string
 * @return          pointer to char array that represents the prefix
 */
char* prefixtostring(meas_prefix_t prefix)
{
    /*
     * Character array to convert the enum prefix to a string. 
     * CAUTION! This Array must be kept in sync with the enum meas_prefix in 
     *          pressure.h
     */
    char *meas_prefix_string[] = 
    {
        "YOTTA",
        "ZETTA",
        "EXA  ",
        "PETA ",
        "TERA ",
        "GIGA ",
        "MEGA ",
        "KILO ",
        "ZERO ",
        "MILLI",
        "MIKRO",
        "NANO ",
        "PICO ",
        "FEMTO",
        "ATTO ",
        "ZEPTO",
        "YOKTO",
        "LAST "
    };
    return meas_prefix_string[prefix];
}


void removefield(field_t field)
{
    unsigned int i;
    for (i = 0; i < field.rows; i++)
    {
        free(field.measurement[i]);
    }
    free(field.measurement);
}