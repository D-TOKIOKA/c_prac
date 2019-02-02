#include <stdio.h>

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

#endif
