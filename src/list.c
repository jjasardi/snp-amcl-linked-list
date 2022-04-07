#include "list.h"

#include <stdbool.h>
#include <stdlib.h>

#include "person.h"

int currentSize = 0;

bool has_next(node_t *head, node_t *listStart) {
  return head->next != listStart;
}

node_t *list_get_last_element(node_t *head) {
  node_t *currentNode = head;
  while (has_next(currentNode, head)) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

void list_insert(person_t person, node_t *head) {
  node_t *lastNode = list_get_last_element(head);
  node_t *newNode = malloc(sizeof(node_t));
  newNode->content = person;
  newNode->next = head;
  lastNode->next = newNode;
}
