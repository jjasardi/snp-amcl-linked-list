#include "person.h"

typedef struct node {
  person_t content;
  struct node *next;
} node_t;
