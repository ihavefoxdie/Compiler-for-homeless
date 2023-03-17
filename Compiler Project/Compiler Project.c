#include "alloc/segment.h"
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    segment* segment = create_segment(1024);
    //printf("%ld\n", segment->alive_blocks->size);
    //printf("%ld\n", segment->dead_blocks->size);
    //printf("fafaf\n");

    block* firstB = add_block_to_segment(segment, 10);
    //block *secondB = add_block_to_segment(segment, 20);
    //block *thirdB = add_block_to_segment(segment, 7);
    //block *fourthB = add_block_to_segment(segment, 8);
    //block *fifthB = add_block_to_segment(segment, 5);
    //printf("%ld", segment->alive_blocks->size);
    //print_all_blocks(segment);
    destroy_segment(segment);
    return 0;
}