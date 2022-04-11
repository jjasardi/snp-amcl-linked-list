#ifndef list_h
#define list_h

#include "person.h"

typedef struct node
{
  person_t content;  // in diesem Knoten gespeicherte Person
  struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;

void list_clear(node_t *root);

// TODO
// list_insert()
// list_remove()

#endif