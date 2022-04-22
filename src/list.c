#include "list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void askForName(){}

void searchForMatch(person_t *personToDelete, node_t *nodePointer, int *searching){
  printf("is in method searchFOrMatch!");
  node_t *nextNodePointer = nodePointer->next;
  if(strlen(nodePointer->content.name) == 0) {
    printf("No Person found with this name!");
    *searching = 0;
    return;
  }
  if(person_compare(personToDelete, &nextNodePointer->content) != 0) {
    nextNodePointer = nextNodePointer->next;
  } else {
    nodePointer->next = nextNodePointer->next;
    free(nextNodePointer);
    printf("Person is deleted!");
    return;
  }
}

void compareNode(person_t personToDelete, node_t *rootPointer){
  printf("is in method compareNode!");
  node_t *nextNodePointer = rootPointer->next;

  int searching = 1;

  while (searching == 1){
    printf("is searching in method compareNode!");

    searchForMatch(&personToDelete, nextNodePointer, &searching);
  }  
}

void list_remove(node_t *rootPointer, person_t personToDelete) {
  printf("is in method list_remove!");
  compareNode(personToDelete, rootPointer);
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

void printNode(node_t *node) { printf("%s\n", node->content.name); }

node_t *getLastNode(node_t *head) {
  node_t *currentNode = head;
  while (currentNode->next != head) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

void list_insert(person_t person, node_t *head) {
  if (strlen(person.name) == 0 && strlen(person.first_name) == 0) {
    fprintf(stderr, "Cannot insert empty person\n");
    return;
  }
  if (person_compare(&person, &head->next->content) == 0) {
    fprintf(stderr, "This record already exists in the list.\n");
    return;
  }
  int personCompare = person_compare(&person, &head->next->content);
  if (strlen(head->next->content.name) == 0 || personCompare < 0) {
    node_t *newNode = getNewNode(person, head->next);
    head->next = newNode;
    return;
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
}
