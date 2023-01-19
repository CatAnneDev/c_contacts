/* Catherine Seymour */

#include "displaydata.h"

void display_options()
{
  printf("\nS: Search\nA: Add\nD: Delete\nQ: Quit\n");
  printf("Choice: ");
}

void search_entries(Contact* contacts[], size_t* count_ptr)
{
  char search_string[MAX_NAME_CHARS + 2];
  char name_string[MAX_NAME_CHARS];
  size_t index;
  
  printf("Enter search string: ");
  fgets(search_string, MAX_LINE_CHARS + 2, stdin);

  /* remove the trailing newline and convert to case insensitive */
  strtok(search_string, "\n");
  to_lowercase(search_string);

  printf("\n");
  for(index = 0; index < (*count_ptr); index++)
  {
    strncpy(name_string, contacts[index]->name,
	    strlen(contacts[index]->name));
    to_lowercase(name_string);
    
    if(strstr(name_string, search_string) != NULL)
    {
     printf("%zu: %s\t%s\t%s", index, contacts[index]->name,
	    contacts[index]->phone, contacts[index]->email);
    }
  }
}

void to_lowercase(char* string)
{
  size_t index;
  
  for (index = 0; index < strlen(string); index++)
  {
    string[index] = (char) tolower((unsigned char) string[index]);
  }
}

void display_entries(Contact* contacts[], size_t* count_ptr)
{
  size_t index;
  printf("\n");

  /* for each contact in contacts array, print its name, phone, and email */
  for(index = 0; index < (*count_ptr); index++)
  {
    printf("%zu: %s\t%s\t%s", index, contacts[index]->name,
	   contacts[index]->phone, contacts[index]->email);
  }
}
