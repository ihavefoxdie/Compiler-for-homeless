#include "os_alloc.h"
#include "error.h"

void* os_malloc(size_t size)
{
	void* res;

	if((res = malloc(size)) == NULL)
		handle_error("error.");
	return res;
}

void os_free(void *ptr)
{
	free(ptr);
}
