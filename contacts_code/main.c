/* Catherine Seymour */

#include "iodata.h"
#include "displaydata.h"
#include "editdata.h"

int main(int argc, char** argv)
{
  Contact* contacts[MAX_CONTACT_COUNT];
  size_t contact_count = 0;
  size_t* count_ptr = &contact_count;

  FILE *file;
  char user_action[INPUT_SIZE];

  /* test if command arguments exist */
  if (argc != 2)
  {
    fprintf(stderr, "usage: %s filename\n", argv[0]);
    return 1;
  }

  /* test if file exists */
  if((file = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "error: file not found\n");
    return 1;
  }

  /* Create an array of contact structs from input file */
  input_entries(argv[1], contacts, count_ptr);
  display_entries(contacts, count_ptr);

  /* Loop for user actions search, add, delete, and finally quit */
  while (user_action[0] != 'q' && user_action[0] != 'Q')
  {
    display_options();
    fgets(user_action, sizeof(user_action), stdin);
    
    if (user_action[0] == 's' || user_action[0] == 'S')
    {
      search_entries(contacts, count_ptr);
    }
    else if (user_action[0] == 'a' || user_action[0] == 'A')
    {
      add_entry(contacts, count_ptr);
      display_entries(contacts, count_ptr);
    }
    else if (user_action[0] == 'd' || user_action[0] == 'D')
    {
      delete_entry(contacts, count_ptr);
      display_entries(contacts, count_ptr);
    }
  }
  
  /* Overwrite initial input file with updated contacts array */
  output_entries(argv[1], contacts, count_ptr);
  printf("\nGoodbye\n");
}
