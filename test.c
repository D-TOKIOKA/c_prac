#include <stdio.h>
#include "print_test.h"
#include <string.h>

void main(){
  struct test_struct ts;

  printf("Hello World""\n");
  print_test(10);

  memset(&ts, 0, sizeof(struct test_struct));
  print_struct(&ts);

  ts.a = 10;
  ts.b = 20;
  ts.c = 30;
  strcpy(ts.d, "TEST\0");
  ts.ts1.a1 = 100;
  strcpy(ts.ts1.buf, "REST\0");
  print_struct(&ts);

}
