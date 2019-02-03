#ifndef __PRINT_TEST__

#define __PRINT_TEST__

struct test_struct {
    int a;
    int b;
    int c;
    char d[4];
};

void print_test(int val);
void print_struct(struct test_struct *);

#endif
