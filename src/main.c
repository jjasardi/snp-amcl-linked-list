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

typedef enum {
  INSERT = 1,
  REMOVE,
  CLEAR,
  QUIT,
} commands_t;

void printNode(node_t* node) {
  printf("{\n");
  printf("  name: %s\n", node->content.name);
  printf("  firstname: %s\n", node->content.first_name);
  printf("  age: %d\n", node->content.age);
  printf("},\n");
}

void validateReturnCode(return_codes_t code, char successMessage[]) {
  switch (code) {
    case SUCCESS:
      printf("%s\n", successMessage);
      break;

    case NOT_FOUND:
      fprintf(stderr, "%s\n", NOT_FOUND_MESSAGE);
      break;

    case EMPTY_PERSON:
      fprintf(stderr, "%s\n", EMPTY_PERSON_MESSAGE);
      break;

    case DUPLICATE_PERSON:
      fprintf(stderr, "%s\n", DUPLICATE_PERSON_MESSAGE);
      break;

    default:
      break;
  }
}

void getPersonData(person_t* person) {
  printf("Name: ");
  scanf("%s", person->name);
  printf("First name: ");
  scanf("%s", person->first_name);
  printf("Age: ");
  scanf("%d", &person->age);
}

void executeCommand(commands_t command, node_t* head) {
  person_t person;
  switch (command) {
    case INSERT:
      getPersonData(&person);
      validateReturnCode(list_insert(person, head), INSERTED_MESSAGE);
      break;

    case REMOVE:
      getPersonData(&person);
      validateReturnCode(list_remove(head, person), REMOVED_MESSAGE);
      break;

    case CLEAR:
      list_clear(head);
      printf("%s\n", CLEARED_MESSAGE);
      break;

    case QUIT:
      break;

    default:
      fprintf(stderr, "Unknown command\n");
  }
}

void printCommands(void) {
  printf("\n");
  printf("%d. Insert\n", INSERT);
  printf("%d. Remove\n", REMOVE);
  printf("%d. Clear\n", CLEAR);
  printf("%d. Quit\n", QUIT);
  printf("\n");
}

void printList(node_t* head) {
  node_t* current = head->next;
  while (strlen(current->content.name)) {
    printNode(current);
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
int main(int argc, char* argv[]) {
  int inputCommand;
  node_t* head = newLinkedList();

  do {
    printList(head);
    printCommands();
    printf("Enter command: ");
    scanf("%d", &inputCommand);
    executeCommand(inputCommand, head);
  } while (inputCommand != QUIT);

  return EXIT_SUCCESS;
}
