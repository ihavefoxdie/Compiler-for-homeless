#include "block_array.h"
#include <string.h>
#include "../core/os_alloc.h"
#include <stdio.h>

block_array* create_block_array(size_t cap)
{
    block_array *arr = os_malloc(sizeof(block_array));
    arr->blocks = os_malloc(sizeof(block*) * cap);
    arr->cap = cap;
    arr->size = 0;

    return arr;
}

void destroy_block_array(block_array *arr)
{
    for(int i = 0; i < arr->size; ++i)
        destroy_block(arr->blocks[i]);
    os_free(arr);
}

static void resize(block_array *ba)
{
    block **barr = os_malloc(sizeof(block*) * ba->size * 2);
    barr = memcpy(barr, ba->blocks, ba->size);
    os_free(ba->blocks);
    ba->blocks = barr;
}

void add_to_block_array(block_array *ba, block *block)
{
    if(ba->size == ba->cap)
        resize(ba);

    printf("ya dolboeb.\n");    
    ba->blocks[ba->size++] = block;
}

void remove_from_block_array(block_array *ba, block *block)
{
    int i = 0;
    for(; i < ba->size; ++i)
        if(ba->blocks[i] == block)
            break;
    
    if(i == ba->size)
        return;

    for(;i < ba->size - 1; ++i)
        ba->blocks[i] = ba->blocks[i + 1];
    ba->blocks[ba->size] = NULL;
    --ba->size;
}
