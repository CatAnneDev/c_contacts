/* Catherine Seymour */

#include "iodata.h"

void input_entries(const char* filename, Contact* contacts[],
		   size_t* count_ptr)
{
  FILE* input_file = fopen(filename, "r");

  char line[MAX_LINE_CHARS];
  uint8_t loop_count = 0;
  char* token;
  
  /* loop through each line in input file*/
  while(fgets(line, MAX_LINE_CHARS, input_file))
  {
    if (strncmp(line, "\n", 1) != 0)
    {
      contacts[loop_count] = malloc(sizeof(Contact));
    
      /* get name */
      token = strtok(line, "\t");
      strncpy(contacts[loop_count]->name, token, strlen(token));

      /* get phone number */
      token = strtok(NULL, "\t");
      strncpy(contacts[loop_count]->phone, token, strlen(token));
    
      /* get email address */ 
      token = strtok(NULL, "\t");
      strncpy(contacts[loop_count]->email, token, strlen(token));

      (*count_ptr)++;
      loop_count++;
    }
  }
  
  fclose(input_file);
}

void output_entries(const char* filename, Contact* contacts[],
		    size_t* count_ptr)
{
  FILE* output_file = fopen(filename, "w");
  size_t index;

  /* overwrite input file with new contacts database */
  for (index = 0; index < (*count_ptr); index++)
  {
    fprintf(output_file, "%s\t%s\t%s", contacts[index]->name,
	   contacts[index]->phone, contacts[index]->email);
  }
  fprintf(output_file, "\n");

  /* free dynamically allocated contacts in contacts array */
  for (index = 0; index < (*count_ptr); index++)
  {
    free(contacts[index]);
  }
  
  fclose(output_file);
}
