#include "segment.h"
#include "block_array.h"
#include "block.h"
#include "../core/os_alloc.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

segment *create_segment(size_t size)
{
    segment *segment = os_malloc(sizeof(segment));
    segment->dead_blocks = create_block_array(11);
    printf("d: %ld\n", segment->dead_blocks->size);
    segment->alive_blocks = create_block_array(10);
    printf("a: %ld\n", segment->alive_blocks->size);
    printf("d: %ld\n", segment->dead_blocks->size);
    segment->segment_base = os_malloc(size);
    segment->segment_capacity = size;
    segment->segment_offset = segment->segment_base;
    segment->segment_size = 0;

    return segment;
}

void destroy_segment(segment *segment)
{
    segment->segment_offset = segment->segment_base;
    //destroy_block_array(segment->alive_blocks);
    //destroy_block_array(segment->dead_blocks);
    os_free(segment->segment_base);
    os_free(segment);
}

static void opt(segment *segment)
{
    if(segment->dead_blocks->size == 0)
        return;
    
    uint8_t *ptr = segment->dead_blocks->blocks[0]->block_base;
    for(int i = 0; i < segment->alive_blocks->size; ++i)
    {
        if(segment->alive_blocks->blocks[i]->block_base > ptr)
        {
            ptr = memcpy(ptr, segment->alive_blocks->blocks[i]->block_base, segment->alive_blocks->blocks[i]->block_size);
            ptr += segment->alive_blocks->blocks[i]->block_size;
        }
    }

    segment->segment_offset = ptr;
}

block* add_block_to_segment(segment *segment, size_t size)
{
    size_t result = segment->segment_capacity - segment->segment_size;
    if(result < size)
        return NULL;

    if((uint8_t*)segment->segment_base + segment->segment_capacity - (uint8_t*)segment->segment_offset < size) {}
        opt(segment);

    block *block = create_block(segment->segment_offset, size);

    add_to_block_array(segment->alive_blocks, block);
    (unsigned char*)segment->segment_offset += size;

    return block;
}

void remove_block_from_segment(segment *segment, block *block)
{
    int i = 0;

    for(; i < segment->alive_blocks->size; ++i)
        if(segment->alive_blocks->blocks[i] == block)
            break;

    if(i == segment->segment_size)
        return;

    add_to_block_array(segment->dead_blocks, block);
    remove_from_block_array(segment->alive_blocks, block);
}

void print_all_blocks(segment *segment)
{
    for(int i = 0; i < segment->alive_blocks->size; ++i)
    {
        size_t begin = (unsigned char*)segment->alive_blocks->blocks[i]->block_base - (unsigned char*)segment->segment_base;
        size_t end = begin + segment->alive_blocks->blocks[i]->block_size ;
        printf("%d: %ld : %ld", i + 1, begin, end);
    }
}