/* 
 * A header file containing definitions and the contact struct
 * used by other modules in the Contact DB assignment
 * Catherine Seymour
 */

#ifndef DEFINEDATA_H
#define DEFINEDATA_H

#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
#define MAX_LINE_CHARS 82
#define MAX_CONTACT_COUNT 1024
#define INPUT_SIZE 3

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

#endif
