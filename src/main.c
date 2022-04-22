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

  person_t person1 = {.name = "Doe", .first_name = "John", .age = 43};
  person_t person2 = {.name = "Alabastatan", .first_name = "Jane", .age = 41};
  person_t person3 = {.name = "Heinz", .first_name = "Jane", .age = 42};
  person_t peopleAlphabetic[] = {person2, person3, person1};

  for (int i = 0; i < 3; i++) {
    list_insert(peopleAlphabetic[i], rootPointer);
  }

  printf("Please insert the first name of the person you want to remove: \n");
  char firstName [NAME_LEN];
  scanf("%s", firstName);
  // fgets(firstName, NAME_LEN, stdin);

  printf("Please insert the second name of the person you want to remove: \n");
  char secondName [NAME_LEN];
  scanf("%s", secondName);
  // fgets(secondName, NAME_LEN, stdin);

  printf("Please enter the age of the person you want to remove: \n");
  int age = -1;
  scanf("%d+", &age);

  person_t person;
  strncpy(person.first_name, firstName, NAME_LEN);
  strncpy(person.name, secondName, NAME_LEN);
  person.age = age;

  list_remove(rootPointer, person);
  printList(rootPointer);

  return EXIT_SUCCESS;
}
