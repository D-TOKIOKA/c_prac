#include <stdio.h>
#include "print_test.h"
#include <string.h>
#include <pthread.h>

pthread_mutex_t test_mutex = PTHREAD_MUTEX_INITIALIZER;

void *test_func1(void *param) {
  pthread_t thread_id;
  int i;
  struct test_struct *ts = (struct test_struct *)param;

  thread_id = pthread_self();
  PRAC_PRINT("thread_ID=%ld\n", thread_id);

  pthread_mutex_lock(&test_mutex);

  for(i = 0; i < 10000000; i++) {
    ts->a -= 1;
    ts->b -= 1;
  }

  pthread_mutex_unlock(&test_mutex);

}

void *test_func2(void *param) {
  pthread_t thread_id;
  int i;
  struct test_struct *ts = (struct test_struct *)param;

  thread_id = pthread_self();
  PRAC_PRINT("thread_ID=%ld\n", thread_id);

  pthread_mutex_lock(&test_mutex);

  for(i = 0; i < 10000000; i++) {
    ts->a += 2;
    ts->b += 2;
  }

  pthread_mutex_unlock(&test_mutex);

}

void main(){
  pthread_t thread1;
  pthread_t thread2;
  struct test_struct ts;

  pthread_mutex_init(&test_mutex, NULL);

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

  pthread_create(&thread1, NULL, test_func1, &ts);
  pthread_create(&thread2, NULL, test_func2, &ts);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  print_struct(&ts);

  pthread_mutex_destroy(&test_mutex);
}
