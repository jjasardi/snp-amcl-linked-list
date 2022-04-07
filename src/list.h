#ifndef LIST_H
#define LIST_H
#include "person.h"

typedef struct node {
  person_t content;
  struct node *next;
} node_t;

void list_insert(person_t person, node_t *head);

// list_remove()
// list_clear()

#endif
