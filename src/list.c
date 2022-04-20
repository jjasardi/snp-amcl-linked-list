#include "list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DUMMY_AGE 69

typedef struct node {
  person_t     content; // in diesem Knoten gespeicherte Person
  struct node *next;    // Pointer auf den nächsten Knoten in der Liste
} node_t;

void askForName(){}

void searchForMatch(person_t *person, node_t *nodePointer, int *searching){
  node_t *nextNodePointer = nodePointer->next;
  if(strnlen(nodePointer->content.name, NAME_LEN) == 0) {
    printf("No Person found with this name!");
    *searching = 0;
  }
  if(person_compare(person, &nextNodePointer->content) != 0) {
    nextNodePointer = nextNodePointer->next;
  } else {
    //brauche hier previous node um die zu vernetzen -> Datenfeld?
    nodePointer->next = nextNodePointer->next;
    free(nextNodePointer);
  }
}

void compareNode(person_t person, node_t *rootPointer){
  char *firstName = person.first_name;
  char *secondName = person.name;

  node_t *nextNodePointer = rootPointer->next;

  int searching = 1;

  while (searching == 1){
    searchForMatch(&person, nextNodePointer,&searching);
  }  
}

void list_remove(node_t *rootPointer) {
  printf("Please insert the first name of the person you want to remove: \n");
  char firstName [NAME_LEN];
  fgets(firstName, NAME_LEN, stdin);

  printf("Please insert the second name of the person you want to remove: \n");
  char secondName [NAME_LEN];
  fgets(secondName, NAME_LEN, stdin);

  person_t person = {secondName, firstName, DUMMY_AGE};

  compareNode(person, rootPointer);
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
