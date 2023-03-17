#ifndef COMP_ERROR_H
#define COMP_ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

#endif
