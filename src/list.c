#include <stdlib.h>
#include "person.h"

typedef struct node
{
  person_t content;  // in diesem Knoten gespeicherte Person
  struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;

void list_clear(node_t *root)
{
  node_t *temp = root;
  node_t *current = root->next;

  while (current != root)
  {
    temp = current->next;
    free(current);
    current = temp;
  }
}