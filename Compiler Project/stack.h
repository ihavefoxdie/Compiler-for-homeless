#include "alloc/block.h"
#include "node.h"

typedef struct
{
	node* last;
	unsigned int quantity;
} stack;

extern node* add_node_stack(void* el, stack* st, size_t size);
extern void del_node_stack(node, stack);