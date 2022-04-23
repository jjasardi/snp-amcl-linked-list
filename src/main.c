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

#define MAX_AGE 99

void printList(node_t* head) {
  node_t* current = head->next;
  while (strlen(current->content.name)) {
    printf("%s\n", current->content.name);
    current = current->next;
  }
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an
 * expression syntax error.
 */
int main(int argc, char *argv[]) {
  node_t* rootPointer = newLinkedList();

  printf("Please insert the first name of the person you want to remove: \n");
  char firstName [NAME_LEN];
  scanf("%s", firstName);

  printf("Please insert the second name of the person you want to remove: \n");
  char secondName [NAME_LEN];
  scanf("%s", secondName);

  printf("Please enter the age of the person you want to remove: \n");
  int age = -1;
  scanf("%d+", &age);

  person_t personToDelete;
  strncpy(personToDelete.first_name, firstName, NAME_LEN);
  strncpy(personToDelete.name, secondName, NAME_LEN);
  personToDelete.age = age;

  list_remove(rootPointer, personToDelete);

  return EXIT_SUCCESS;
}
