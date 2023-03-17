#ifndef COMP_BLOCK_ARRAY_H
#define COMP_BLOCK_ARRAY_H
#include "block.h"
#include <stdlib.h>

typedef struct 
{
    block **blocks;
    size_t size;
    size_t cap;
} block_array;


extern block_array* create_block_array(size_t);
extern void destroy_block_array(block_array*);

extern void add_to_block_array(block_array *ba, block *block);
extern void remove_from_block_array(block_array *ba, block *block);

#endif