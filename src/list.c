#include <stdlib.h>
#include "person.h"

typedef struct node
{
  person_t content;  // in diesem Knoten gespeicherte Person
  struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;

void list_clear(struct node_t *list)
{
  struct node_t *temp;

  while (temp != NULL)
  {
    temp = list;
    list = list->next;

    free(temp);
  }
}