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

void list_insert(person_t person, node_t *head, node_t *root) {
  if (head->next == head) {
    node_t *newNode = getNewNode(person, head);
    head->next = newNode;
    return;
  }

  node_t *currentNode = head;
  while (person_compare(&person, &head->content) > 0) {
    currentNode = currentNode->next;
  }

  node_t *newNode = getNewNode(person, currentNode->next);
  currentNode->next = newNode;
}
