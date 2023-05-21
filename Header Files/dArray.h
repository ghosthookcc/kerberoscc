#ifndef DARRAY_H
#define DARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct int32Array
{
	unsigned int realSize;
	unsigned int capacity;
	int* items;
} int32Array;

/* Start int32Array declaration */

int32Array* initInt32Array(unsigned int initCapacity);

void pushInt32(int32Array** target, int item);

void printInt32Array(int32Array** target);

void freeInt32Array(int32Array** target);

/* End int32Array declaration */

#endif