#include "list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

/**
 * @brief Get the Match object
 *
 * @param personToDelete  person to delete
 * @param nodePointer pointer of the current node
 * @param searching termination conition for searching
 * @return node_t*  pointer to the node which contains the person to delete-
 * if exists NULL if person not exists
 */
node_t *getMatch(person_t *personToDelete, node_t *nodePointer,
                 int *searching) {
  if (strlen(nodePointer->next->content.name) == 0) {
    *searching = 0;
    return NULL;
  }

  if (person_compare(personToDelete, &nodePointer->next->content) == 0) {
    *searching = 0;
    return nodePointer->next;
  }
  return NULL;
}

/**
 * @brief removes the given person if exists in linked list
 *
 * @param rootPointer pointer of the root node
 * @param personToDelete  person to delete
 */
return_codes_t list_remove(node_t *rootPointer, person_t personToDelete) {
  node_t *currentNode = rootPointer;
  node_t *foundNode;
  node_t *previousNode;
  int searching = 1;

  while (searching) {
    previousNode = currentNode;
    foundNode = getMatch(&personToDelete, currentNode, &searching);
    currentNode = currentNode->next;
  }
  if (foundNode == NULL) {
    return NOT_FOUND;
  }
  previousNode->next = foundNode->next;
  free(foundNode);
  return SUCCESS;
}

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

node_t *getLastNode(node_t *head) {
  node_t *currentNode = head;
  while (currentNode->next != head) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

return_codes_t list_insert(person_t person, node_t *head) {
  if (strlen(person.name) == 0 && strlen(person.first_name) == 0) {
    return EMPTY_PERSON;
  }
  if (person_compare(&person, &head->next->content) == 0) {
    return DUPLICATE_PERSON;
  }
  int personCompare = person_compare(&person, &head->next->content);
  if (strlen(head->next->content.name) == 0 || personCompare < 0) {
    node_t *newNode = getNewNode(person, head->next);
    head->next = newNode;
    return SUCCESS;
  }
  return list_insert(person, head->next);
}

void list_clear(node_t *root) {
  node_t *temp = root;
  node_t *current = root->next;

  while (current != root) {
    temp = current->next;
    free(current);
    current = temp;
  }
  root->next = root;
}
