#include "os_alloc.h"
#include <stdio.h>

struct test_struct
{
    int a;
    int b;
    char *gg;
};

//int main(void)
//{
//    struct test_struct *ts = os_malloc(sizeof(struct test_struct));
//    ts->a = 5;
//
//    printf("%d\n", ts->a);
//}