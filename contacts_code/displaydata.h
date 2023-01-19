/* 
 * A program that implements functions to:
 * 1. Display options that the user can input
 * 2. Search for entries based on provided target substring
 * 3. Convert a string to its lowercase version
 * 4. Display all entries in the struct array of contacts
 * Catherine Seymour
 */

#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definedata.h"

/*
 * Display options that user can input
 */
void display_options(void);

/*
 * Search for entries based on provided target substring
 * @param contacts array of contact structs to search through for target
 * @param count_ptr the total contacts in contacts array
 */
void search_entries(Contact* contacts[], size_t* count_ptr);

/*
 * Converts string parameter to lowercase version
 * @param string to be converted to lowercase
 */
void to_lowercase(char* string);

/*
 * Display all entries in the struct array of contacts
 * @param contacts array of contact structs to display contacts from
 * @param count_ptr the total contacts in contacts array
 */
void display_entries(Contact* contacts[], size_t* count_ptr);

#endif
