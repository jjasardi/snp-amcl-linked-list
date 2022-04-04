#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "person.h"

/**
 * @brief  Compares two persons in this sequence: 1st=name, 2nd=first_name, 3rd=age
 * @param  a [IN] const reference to 1st person in the comparison
 * @param  b [IN] const reference to 2nd person in the comparison
 * @return =0 if all record fields are the same
 *         >0 if all previous fields are the same, but for this field, a is greater
 *         <0 if all previous fields are the same, but for this field, b is greater
 * @remark strncmp() is used for producing the result of string field comparisons
 * @remark a->age – b->age is used for producing the result of age comparison
 */
int person_compare(const person_t *a, const person_t *b){
    int name_comparison = strcmp(a->name, b->name);
    if (name_comparison != 0) return name_comparison;
    int first_name_comparison = strcmp(a->first_name, b->first_name);
    if (first_name_comparison != 0) return first_name_comparison;
    int age_comparison = (a->age - b->age);
    if (age_comparison != 0) return age_comparison;
    return 0;
}
