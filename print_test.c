#include <stdio.h>
#include "print_test.h"

#ifdef TEST

void print_test(int val){
  printf("input val=[%d]\n", val);
}

#else

#define PRINT(a) printf(a)

void print_test(int val){
  PRINT("TEST\n");

  printf("normal mode=[%d]\n", val);
}

void print_struct(struct test_struct *ts) {
    printf("a = %d\n", ts->a);
    printf("b = %d\n", ts->b);
    printf("c = %d\n", ts->c);
    printf("d = %s\n", ts->d);
}


#endif
