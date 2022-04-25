#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#include "person.h"

typedef struct node {
  person_t content;
  struct node *next;
} node_t;

typedef enum {
  SUCCESS,
  NOT_FOUND,
  EMPTY_PERSON,
  DUPLICATE_PERSON
} return_codes_t;

#define NOT_FOUND_MESSAGE "Person not found"
#define EMPTY_PERSON_MESSAGE "Cannot insert an empty person"
#define DUPLICATE_PERSON_MESSAGE "This record already exists"
#define INSERTED_MESSAGE "Person inserted"
#define REMOVED_MESSAGE "Person removed"
#define CLEARED_MESSAGE "List cleared"

return_codes_t list_insert(person_t person, node_t *head);

node_t *getNewNode(person_t person, node_t *next);

node_t *newLinkedList();

return_codes_t list_remove(node_t *rootPointer, person_t personToDelete);

// list_clear()

void list_clear(node_t *root);

// TODO
// list_insert()
// list_remove()

#endif
