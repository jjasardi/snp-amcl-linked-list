/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void printList(node_t *head, const node_t *root) {
  printf("%s\n", head->content.name);

  if (head->next == root) {
    return;
  }
  printList(head->next, root);
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an
 * expression syntax error.
 */
int main(int argc, char *argv[]) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  person_t person = {.name = "Doe", .first_name = "John", .age = 43};
  person_t person3 = {.name = "Alabastatan", .first_name = "Jane", .age = 41};
  person_t person2 = {.name = "Heinz", .first_name = "Jane", .age = 42};
  node_t *rootPointer = newLinkedList();
  printList(rootPointer, rootPointer);
  printf("First Insert\n");
  list_insert(person, rootPointer, NULL);
  printList(rootPointer, rootPointer);
  printf("Second Insert: \n");
  list_insert(person2, rootPointer, NULL);
  printList(rootPointer, rootPointer);
  printf("Third Insert: \n");
  list_insert(person3, rootPointer, NULL);
  printList(rootPointer, rootPointer);
  // END-STUDENTS-TO-ADD-CODE
  return EXIT_SUCCESS;
}
