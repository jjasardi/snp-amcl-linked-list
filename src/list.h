#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#include "person.h"

typedef struct node {
  person_t content;
  struct node *next;
} node_t;

void list_insert(person_t person, node_t *head);

node_t *getNewNode(person_t person, node_t *next);

node_t *newLinkedList();

// list_remove()
// list_clear()

void list_clear(node_t *root);

// TODO
// list_insert()
// list_remove()

#endif
