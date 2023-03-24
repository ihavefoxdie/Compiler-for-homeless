
#include "alloc/block.h"

typedef struct
{
	node* next;
	node* prev;
	block* data;
} node;

extern void free_node(node* item)
{
	destroy_block(item->data);
	os_free(item);
}