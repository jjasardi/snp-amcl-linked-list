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
 * @brief Test suite for the given package.
 */
#include <CUnit/Basic.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#include "list.h"
#include "person.h"
#include "test_utils.h"

#ifndef TARGET  // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT \
  "\n                "  ///< allow for better stdout formatting in case of error

// setup & cleanup
static int setup(void) {
  remove_file_if_exists(OUTFILE);
  remove_file_if_exists(ERRFILE);
  return 0;  // success
}

static int teardown(void) {
  // Do nothing.
  // Especially: do not remove result files - they are removed in int
  // setup(void) *before* running a test.
  return 0;  // success
}

// tests
static void test_person_compare(void) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  // arrange

  // act
  CU_FAIL("missing test");

  // assert

  // END-STUDENTS-TO-ADD-CODE
}

node_t* create_list(person_t person) {
  node_t* head = malloc(sizeof(node_t));
  head->next = head;
  head->content = person;
  return head;
}

int get_list_length(node_t* head) {
  int length = 1;
  node_t* current = head;
  while (strlen(current->next->content.name) != 0) {
    length++;
    current = current->next;
  }
  return length;
}

void comparePerson(person_t* expected, person_t* actual) {
  CU_ASSERT_STRING_EQUAL(expected->name, actual->name);
  CU_ASSERT_STRING_EQUAL(expected->first_name, actual->first_name);
  CU_ASSERT_EQUAL(expected->age, actual->age);
}

void printList(node_t* head) {
  node_t* current = head;
  while (current->next != head) {
    printf("%s\n", current->content.name);
    current = current->next;
  }
}

static void test_list_insert(void) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  // arrange
  person_t person = {.name = "Doe", .first_name = "John", .age = 43};
  person_t person2 = {.name = "Alabastatan", .first_name = "Jane", .age = 41};
  person_t person3 = {.name = "Heinz", .first_name = "Jane", .age = 42};
  person_t person4 = {.name = "Alban", .first_name = "Jane", .age = 41};
  person_t person5 = {.name = "Alban", .first_name = "Jane", .age = 42};
  person_t person6 = {.name = "Alban", .first_name = "Jane", .age = 42};
  person_t emptyPerson = {.name = "", .first_name = "", .age = 0};
  person_t people[] = {person, person2, person3, person4, person5, person6};
  person_t peopleAlphabetic[] = {person2, person4, person5, person, person3};
  node_t* rootPointer = newLinkedList();
  for (int i = 0; i < 5; i++) {
    list_insert(people[i], rootPointer);
  }
  CU_ASSERT_EQUAL(get_list_length(rootPointer), 6);
  node_t firstNode = *rootPointer->next;
  node_t secondNode = *firstNode.next;
  node_t thirdNode = *secondNode.next;
  node_t fourthNode = *thirdNode.next;
  node_t fifthNode = *fourthNode.next;
  node_t nodes[] = {firstNode, secondNode, thirdNode, fourthNode, fifthNode};

  for (int i = 0; i < 5; i++) {
    comparePerson(&peopleAlphabetic[i], &nodes[i].content);
  }
  list_insert(emptyPerson, rootPointer);
  CU_ASSERT_EQUAL(get_list_length(rootPointer), 6);
  // END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  // arrange

  // act
  CU_FAIL("missing test");

  // assert

  // END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  // arrange
  node_t *rootPointer = newLinkedList();
  person_t person = {.name = "Doe", .first_name = "John", .age = 43};
  person_t person2 = {.name = "Alabastatan", .first_name = "Jane", .age = 41};
  person_t person3 = {.name = "Heinz", .first_name = "Jane", .age = 42};
  person_t person4 = {.name = "Alban", .first_name = "Jane", .age = 41};
  person_t people[] = {person, person2, person3, person4};
  for (int i = 0; i < 4; i++) {
    list_insert(people[i], rootPointer);
  }
  list_clear(rootPointer);

  // assert
  CU_ASSERT_EQUAL(rootPointer->next, rootPointer);
  // END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void) {
  // setup, run, teardown
  TestMainBasic("lab test", setup, teardown, test_person_compare,
                test_list_insert, test_list_remove, test_list_clear);
}
