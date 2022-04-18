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
