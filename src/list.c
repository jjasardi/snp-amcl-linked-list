#include "person.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 20
#define DUMMY_AGE 69

typedef struct node {
  person_t     content; // in diesem Knoten gespeicherte Person
  struct node *next;    // Pointer auf den nächsten Knoten in der Liste
} node_t;

void askForName(){}

void searchForMatch(person_t *person, node_t *nodePointer, node_t *rootPointer, int *searching){
  node_t *nextNodePointer = &nodePointer->next;
  if(&nodePointer == &rootPointer) {
    printf("No Person found with this name!");
    *searching = 0;
  }
  if(person_compare(&person, &nextNodePointer != 0)) {
    nextNodePointer = &nextNodePointer->next;
  } else {
    //brauche hier previous node um die zu vernetzen -> Datenfeld?
    free(nodePointer);
  }
}

void compareNode(person_t person, node_t *rootPointer){
  char *firstName = person.first_name;
  char *secondName = person.name;

  node_t *nextNodePointer = &rootPointer->next;

  int *searching = 1;

  while (searching == 1){
    searchForMatch(&person, &nextNodePointer, rootPointer, *searching);
  }  
}

void list_remove(node_t *rootPointer) {
  printf("Please insert the first name of the person you want to remove: \n");
  char firstName [MAX_NAME_LENGTH];
  fgets(firstName, MAX_NAME_LENGTH, stdin);

  printf("Please insert the second name of the person you want to remove: \n");
  char secondName [MAX_NAME_LENGTH];
  fgets(secondName, MAX_NAME_LENGTH, stdin);

  person_t person = {secondName, firstName, DUMMY_AGE};

  compareNode(person, rootPointer);
}
