/* 
 * File:   pressure.h
 * Author: daniw
 *
 * Created on 23. März 2014, 14:32
 */

#ifndef PRESSURE_H
#define	PRESSURE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VALUEMAX  100                   // Maximal value for random numbers
#define VALUEPREC 1000                  // Used to define random precision
#define MEMLIMIT  400000000             // Limit of entries in field

typedef enum meas_prefix_
{
    YOTTA,
    ZETTA,
    EXA,
    PETA,
    TERA,
    GIGA,
    MEGA,
    KILO,
    ZERO,
    MILLI,
    MIKRO,
    NANO,
    PICO,
    FEMTO,
    ATTO,
    ZEPTO,
    YOKTO,
    LAST
} meas_prefix_t;

typedef struct measurement_
{
    float           value;
    meas_prefix_t   prefix;
} measurement_t;

typedef struct field_
{
    measurement_t** measurement;
    unsigned int    rows;
    unsigned int    columns;
} field_t;

/**
 * Function to create an uninitialized measurement field
 * @param rows    number of rows
 * @param columns number of columns
 * @return        struct with pointer to measurements, number of rosw, number of columns
 */
field_t createfield(unsigned int rows, unsigned int columns);

/**
 * Function to fill the field with one single value and prefix
 * @param field     field to be filled
 * @param value     value to be filled in each measurement in field
 * @param prefix    prefex to be filled in each measurement in field
 */
void fillfield(field_t field, float value, meas_prefix_t prefix);

/**
 * Function to fill the field with random values and prefixes
 * Used to simulate an actual measurement
 * The measurements are filled with random values and prefixes
 * @param field     field to be filled with random measurements
 */
void simfield(field_t field);

/**
 * Function to fill the field with values and prefixes as in example
 * @param field     field to be filled with example measurements
 */
void examplefield(field_t field);

/**
 * Function to get one measurement from a field
 * @param row       row in field, from where the measurement is read
 * @param column    column in field, from where the measurement is read
 * @return          measurement
 */
measurement_t getmeasurement(field_t field, unsigned int row, unsigned int column);

/**
 * Function to set one measurement in a field
 * @param field         field in which the measurement is set
 * @param row           row in field, in which the measurement is set
 * @param column        column in field, in which the measurement is set
 * @param measurement   measurement to be copied to field. 
 */
void setmeasurement(field_t field, unsigned int row, unsigned int column, measurement_t measurement);

/**
 * Function to print all the measurements in a field
 * @param field     field to be printed
 */
void printfield(field_t field);

/**
 * Function to print one single measurement
 * @param measurement   measurement to be printed
 */
void printmeasurement(measurement_t measurement);

/**
 * Function that returns a string according to a prefix given
 * @param prefix    prefix to be turned to a string
 * @return          pointer to char array that represents the prefix
 */
char* prefixtostring(meas_prefix_t prefix);

/**
 * Function to remove a field
 * @param field     field to be removed
 */
void removefield(field_t field);

#ifdef	__cplusplus
}
#endif

#endif	/* PRESSURE_H */

