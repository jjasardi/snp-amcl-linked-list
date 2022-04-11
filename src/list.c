#include "list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

node_t *getNewNode(person_t person, node_t *next) {
  node_t *newNode = malloc(sizeof(node_t));
  newNode->content = person;
  newNode->next = next;
  return newNode;
}

node_t *newLinkedList() {
  node_t *head = malloc(sizeof(node_t));
  head->next = head;
  return head;
}

bool has_next(node_t *head, node_t *listStart) {
  return head->next != listStart;
}

void printNode(node_t *node) { printf("%s\n", node->content.name); }

node_t *getLastNode(node_t *head) {
  node_t *currentNode = head;
  while (currentNode->next != head) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

void list_insert(person_t person, node_t *head, node_t *previous) {
  if (person_compare(&person, &head->content) == 0) {
    fprintf(stderr, "This record already exists in the list.\n");
    return;
  }
  int personCompare = strcmp(head->content.name, person.name);
  printf("Name in List: %s\n", head->content.name);
  printf("Name in struct: %s\n", person.name);
  printf("Person Compare: %d\n", personCompare);
  if ((personCompare <= 0 && strlen(head->content.name) > 0) ||
      strlen(head->content.name) == 0) {
    node_t *newNode = getNewNode(person, head->next);
    head->next = newNode;
  } else {
    return list_insert(person, head->next, head);
  }
}
