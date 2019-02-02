#include <stdio.h>

#ifdef TEST

void print_test(int val){
  printf("input val=[%d]\n", val);
}

#else

void print_test(int val){
  printf("input val=[%d]\n", val);
}

##endif
