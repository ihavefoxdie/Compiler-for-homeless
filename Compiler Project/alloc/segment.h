#ifndef COMP_SEGMENT_H
#define COMP_SEGMENT_H
#include <stdlib.h>
#include "block_array.h"

typedef struct
{
	void *segment_base;
	void *segment_offset;
	size_t segment_capacity;
	size_t segment_size;
	block_array *alive_blocks;
	block_array *dead_blocks;
} segment;

extern segment* create_segment(size_t);
extern void destroy_segment(segment*);

extern block *add_block_to_segment(segment*, size_t);
extern void remove_block_from_segment(segment*, block*);
extern void print_all_blocks(segment *segment);
#endif
