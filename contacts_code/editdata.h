/* 
 * A program that implements functions to:
 * 1. Add an entry to the array of contact structs
 * 2. Delete an entry from the array of contact structs
 * Catherine Seymour
 */

#ifndef EDITDATA_H
#define EDITDATA_H

#include <stdio.h>
#include <stdlib.h>
#include "iodata.h"

/*
 * Add an entry to an array of contacts
 * @param contacts array of contact structs to add a contact to the end of it
 * @param count_ptr the total contacts in contacts array
 */
void add_entry(Contact* contacts[], size_t* count_ptr);

/*
 * Delete an entry from an array of contacts
 * @param contacts array of contact structs to access a contact to delete
 * @param count_ptr the total contacts in contacts array
 */
void delete_entry(Contact* contacts[], size_t* count_ptr);

#endif
