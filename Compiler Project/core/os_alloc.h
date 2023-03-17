#ifndef COMP_OS_ALLOC_H
#define COMP_OS_ALLOC_H
#include <stdlib.h>

extern void *os_malloc(size_t);
extern void *os_calloc(size_t);
extern void *os_realloc(size_t);
extern void os_free(void*);

#endif
