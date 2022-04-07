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

void print_list(node_t* head, node_t* listStart) {
  printf("[%s]\n", head->content.first_name);
  if (head->next == listStart) {
    return;
  }
  print_list(head->next, listStart);
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an
 * expression syntax error.
 */
int main(int argc, char* argv[]) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  node_t* head = malloc(sizeof(node_t));
  head->next = head;
  person_t person = {.name = "Doe", .first_name = "John", .age = 42};
  person_t person2 = {.name = "Doe", .first_name = "Jane", .age = 43};
  person_t person3 = {.name = "Doe", .first_name = "Jack", .age = 44};
  person_t person4 = {.name = "Doe", .first_name = "Jill", .age = 45};
  head->content = person;
  list_insert(person2, head, head);
  list_insert(person3, head, head);
  list_insert(person4, head, head);
  print_list(head, head);
  // END-STUDENTS-TO-ADD-CODE
  return EXIT_SUCCESS;
}
