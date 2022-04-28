#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H
#include "mybool.h"
unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath);


void array_dump(int a[], unsigned int length);

mybool array_is_sorted(int a[], unsigned int max_size);

void array_swap(int a[], unsigned int i, unsigned int j);


#endif
