#ifndef person_h
#define person_h        

#define NAME_LEN 20

typedef struct {
  char         name[NAME_LEN];
  char         first_name[NAME_LEN];
  unsigned int age;
} person_t;

int person_compare(const person_t *a, const person_t *b);

#endif