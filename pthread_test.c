
#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct st_thread_info
{
  pthread_t internal_thd;
  int internal_value;
};

struct xyz_axis
{
  pthread_mutex_t xyz_mtx;
  int x;
  int y;
  int z;
};

void *test0(void *param)
{
  int i = 0;
  struct xyz_axis *xyz;
  pthread_t tid;

  xyz = (struct xyz_axis *) param;
  printf("xyz [%p] x=%d, y=%d, z=%d\n", xyz, xyz->x, xyz->y, xyz->z);

#ifdef MUTEXON
  pthread_mutex_lock(&xyz->xyz_mtx);
#endif
  for (i = 0; i < 1000; i++)
  {
    //    printf("[%d] TH ID=%lu\n", i, pthread_self);
    xyz->x += i;
    xyz->y += 2 * i;
    xyz->z -= i;
    usleep(100);
  }

#ifdef MUTEXON
  pthread_mutex_unlock(&xyz->xyz_mtx);
#endif
  printf("Result xyz [%p] x=%d, y=%d, z=%d\n", xyz, xyz->x, xyz->y, xyz->z);
  //  printf("pthread result=%d\n", a->internal_value);
  return (void*)xyz;

}

void *test1(void *param)
{
  int i = 0;
  struct xyz_axis *xyz;
  pthread_t tid;

  xyz = (struct xyz_axis *) param;
  printf("xyz [%p] x=%d, y=%d, z=%d\n", xyz, xyz->x, xyz->y, xyz->z);

#ifdef MUTEXON
  pthread_mutex_lock(&xyz->xyz_mtx);
#endif
  for (i = 0; i < 1000; i++)
  {
    //    printf("[%d] TH ID=%lu\n", i, pthread_self);
    xyz->x -= i;
    xyz->y -= i;
    xyz->z += 3 * i;
    usleep(500);
  }

#ifdef MUTEXON
  pthread_mutex_unlock(&xyz->xyz_mtx);
#endif
  printf("Result xyz [%p] x=%d, y=%d, z=%d\n", xyz, xyz->x, xyz->y, xyz->z);
  //  printf("pthread result=%d\n", a->internal_value);
  return (void*)xyz;

}


void main()
{
  struct st_thread_info th_info0;
  struct st_thread_info th_info1;
  struct xyz_axis xyz;
  int ret;
  int arg = 12345;
  void *result;

  xyz.x = 0;
  xyz.y = 0;
  xyz.z = 0;

  printf("Hello world\n");

  th_info0.internal_value = 0;
  th_info1.internal_value = 10;

  pthread_mutex_init(&xyz.xyz_mtx, NULL);
  
  ret = pthread_create(&(th_info0.internal_thd), NULL, test0, &xyz);
  ret = pthread_create(&(th_info1.internal_thd), NULL, test1, &xyz);

  ret = pthread_join(th_info0.internal_thd, &result);
  ret = pthread_join(th_info1.internal_thd, &result);

  printf("Thread Finish\n");

}
