#include "stack.h"
#include "core/os_alloc.h"


node* add_node_stack(void* el, stack* st, size_t size)
{
	node* item = os_malloc(sizeof(node));
	item->data = create_block(el, sizeof(block));

	if (st->last != NULL) {
		st->last->next = item;
		item->prev = st->last;
	}
	item->next = NULL;
	st->last = item;
	write_block(item->data, el, size);

	st->quantity++;
	return item;
}

void del_node_stack(stack* st)
{
	if (st->last != NULL) {
		node* temp = st->last;

		if (st->last->prev != NULL)
		{
			st->last = st->last->prev;
			st->last->next = NULL;
		}
		else
		{
			st->last = NULL;
		}
		st->quantity--;


		free_node(temp);
	}
}