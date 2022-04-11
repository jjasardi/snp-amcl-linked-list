#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#include "person.h"

typedef struct node {
  person_t content;
  struct node *next;
} node_t;

void list_insert(person_t person, node_t *head, const node_t *root);

node_t *getNewNode(person_t person, node_t *next);

// list_remove()
// list_clear()

#endif
