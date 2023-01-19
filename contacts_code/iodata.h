/* 
 * A program that implements functions to:
 * 1. Read contents of a file into an array of contact structs
 * 2. Write the updated contacts array's structs back out to file
 * Catherine Seymour
 */

#ifndef IODATA_H
#define IODATA_H

#include "definedata.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Read contents of a file to input contact data into an array of structs
 * @param filename the input file containing contacts info
 * @param contacts the array of contact structs
 * @param count_ptr total contacts count in contacts array
 */
void input_entries(const char* filename, Contact* contacts[],
		   size_t* count_ptr);

/*
 * Writes the contacts array's structs back out to the file
 * @param filename the output file
 * @param contacts the array of contacts to be written to the output file
 * @param count_ptr total contacts count in contacts array
 */
void output_entries(const char* filename, Contact* contacts[],
		    size_t* count_ptr);

#endif
