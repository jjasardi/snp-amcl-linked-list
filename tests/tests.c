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
  while (current->next != head) {
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

static void test_list_insert(void) {
  // BEGIN-STUDENTS-TO-ADD-CODE
  // arrange
  person_t person = {.name = "Doe", .first_name = "John", .age = 42};
  person_t person2 = {.name = "Doe", .first_name = "Jane", .age = 43};
  // act
  node_t* list = create_list(person);
  // assert
  CU_ASSERT_EQUAL(get_list_length(list), 1);
  comparePerson(&person, &list->content);
  list_insert(person2, list);
  CU_ASSERT_EQUAL(get_list_length(list), 2);
  comparePerson(&person, &list->content);
  comparePerson(&person2, &list->next->content);
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

  // act
  CU_FAIL("missing test");

  // assert

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
