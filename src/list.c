#include <stdlib.h>
#include "list.h"

void list_clear(node_t *root)
{
  node_t *temp = root;
  node_t *current = root->next;

  while (current != root)
  {
    temp = current->next;
    free(current);
    current = temp;
  }
}