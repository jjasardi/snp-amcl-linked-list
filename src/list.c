#include "person.h"
#include <stdlib.h>

person_t root_t;
int rootPointer;
node_t currentNode;
int amountOfNodes = 0;

typedef struct node {
  person_t     content; // in diesem Knoten gespeicherte Person
  struct node *next;    // Pointer auf den nächsten Knoten in der Liste
} node_t;

void initialiseRoot(){
  node_t *rootPointer, rootNode;
  rootPointer = &rootNode;

  rootNode.content = root_t;
  rootNode.next = rootPointer;
  currentNode = rootNode;
  amountOfNodes++;
}

int checkIfLastNode(int nodePointer){
  if(nodePointer > amountOfNodes * (sizeof(node_t))){
    return 1;
  } else {
    return 0;
  }
}

int checkIfEnoughMemory(){
  if (!malloc(amountOfNodes * (sizeof(node_t))) == 0){
      return 1;
    } else {
    printf("ERROR");
    return 0;
  }
}

//TODO insert method header in .h file 
void insert(person_t person) {
  node_t *nodePointer, newNode;
  nodePointer = &newNode;
  newNode.content = person;

  if(checkIfEnoughMemory == 1) {
    if((checkIfLastNode(nodePointer) == 1)) {
      currentNode.next = rootPointer;
    } else {
      currentNode.next = malloc((sizeof(node_t)));
    }
  }
}
  