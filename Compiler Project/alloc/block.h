#ifndef COMP_BLOCK_H
#define COMP_BLOCK_H
#include <stdlib.h>

#define BLOCK_NAME_LENGTH 16

typedef struct block
{
	//const char block_name[BLOCK_NAME_LENGTH];  hash.
	void *block_base;
	size_t block_size; 
} block;

extern block *create_block(void*, size_t);
extern void destroy_block(block*);

extern int read_block(block *block, void *buffer, size_t size);
extern int write_block(block *block, void *from, size_t size);

//extern unsigned int get_hash(block*);
#endif
