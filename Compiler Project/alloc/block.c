#include "block.h"
#include "../core/os_alloc.h"
#include <stdint.h>
#include <string.h>

block* create_block(void *ptr, size_t size)
{
    block *block = os_malloc(sizeof(block));

    block->block_base = ptr;
    block->block_size = size;

    return block;
}

void destroy_block(block *block)
{
    os_free(block);
}

int read_block(block *block, void *data, size_t size)
{
    if(block->block_size < size)
        return -1;
    

    data = memcpy(data, block->block_base, size);

    return 0;
}

int write_block(block *block, void *from, size_t size)
{
    if(block->block_size < size)
        return -1;
    
    block->block_base = memcpy(block->block_base, from, size);

    return 0;
}
