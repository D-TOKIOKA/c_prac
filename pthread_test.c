
#include <stdio.h>
#include <pthread.h>

void *test(void *param)
{
  int i = 0;
  int *a;

  a = (int*)param;
  printf("input value=%d[%p]\n", *a, a);
  
  for (i = 0; i < 10; i++)
  {
    printf("Test[%d]\n", i);
  }

  *a = *a + i;
  printf("Thread Result value=%d [%p]\n", *a, a);

  return (void*)a;

}


void main()
{
    pthread_t tid;
    int ret;
    int arg = 12345;
    void *result;

    printf("Hello world\n");

    ret = pthread_create(&tid, NULL, test, &arg);
    ret = pthread_join(tid, &result);

    printf("Thread Join Result=%d, [%p]\n", *(int*)result, result);

    printf("Thread Finish\n");

}
