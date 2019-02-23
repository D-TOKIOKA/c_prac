#ifndef __PRINT_TEST__

#define __PRINT_TEST__

#define PRAC_PRINT printf

struct test_st {
  int a1;
  char buf[100];
};

struct test_struct {
    int a;
    int b;
    int c;
    char d[4];
    struct test_st ts1;
};

void print_test(int val);
void print_struct(struct test_struct *);

#endif
