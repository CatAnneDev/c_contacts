/* Catherine Seymour */

#include "editdata.h"

void add_entry(Contact* contacts[], size_t* count_ptr)
{
  char name_input[MAX_NAME_CHARS + 2];
  char phone_input[MAX_PHONE_CHARS + 2];
  char email_input[MAX_EMAIL_CHARS + 2];

  /* get the contact's name, phone numbers, and email address */
  printf("Enter the contact's name: ");
  fgets(name_input, MAX_NAME_CHARS + 2, stdin);
  
  printf("Enter the contact's phone number: ");
  fgets(phone_input, MAX_PHONE_CHARS + 2, stdin);

  printf("Enter the contact's email address: ");
  fgets(email_input, MAX_EMAIL_CHARS + 2, stdin);

  /* remove the trailing newlines */
  strtok(name_input, "\n");
  strtok(phone_input, "\n");
  strtok(email_input, "\n");
  printf("Name:%sCharacters:%zu", name_input, strlen(name_input));

  /* dynamically create new contact */
  contacts[(*count_ptr)] = malloc(sizeof(Contact));

  strncpy(contacts[(*count_ptr)]->name, name_input, strlen(name_input));
  strncpy(contacts[(*count_ptr)]->phone, phone_input, strlen(phone_input));
  strncpy(contacts[(*count_ptr)]->email, email_input, strlen(email_input));

  (*count_ptr)++;
}

void delete_entry(Contact* contacts[], size_t* count_ptr)
{
  char id_input[6];
  size_t id;
  size_t index;

  /* get user inputted id of a target contact*/
  printf("Enter the id of the contact to delete: ");
  fgets(id_input, sizeof(id), stdin);

  /* tranform string id into int */
  id = (size_t) atoi(id_input);

  /* if id is an existing entry in contacts array */
  if(id <= (*count_ptr))
  {
    /* delete contact associated with the id */
    for(index = (size_t) id; index < (*count_ptr) - 1; index++)
    {
      contacts[index] = contacts[index + 1];
    }
    free(contacts[(*count_ptr)]);
    (*count_ptr)--;
  }
}
