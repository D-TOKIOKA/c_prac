#include <stdio.h>
#include "print_test.h"
#include <string.h>
#include <pthread.h>

void *test_func(void *param) {
  pthread_t thread_id;
  struct test_struct *ts = (struct test_struct *)param;

  thread_id = pthread_self();
  PRAC_PRINT("thread_ID=%ld\n", thread_id);
  ts->a = 100;
  print_struct(ts);
}

void main(){
  pthread_t thread;
  int pid;
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

  pthread_create(&thread, NULL, test_func, &ts);
  pthread_join(thread, NULL);
}
