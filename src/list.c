#include "list.h"

#include <stdlib.h>

#include "person.h"

int currentSize = 0;

void list_insert(person_t person, node_t *head, node_t *listStart) {
  if (head->next == listStart) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->content = person;
    newNode->next = listStart;
    head->next = newNode;
    return;
  }
  list_insert(person, head->next, listStart);
}
