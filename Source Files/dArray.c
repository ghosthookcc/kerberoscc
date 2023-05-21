#include "../Header Files/dArray.h"

/* Start int32Array definition */

int32Array* initInt32Array(unsigned int initCapacity)
{
	int32Array* new = (int32Array*)malloc(sizeof(int32Array*) + (sizeof(int) * initCapacity));
	
	new->items = (int*)malloc(sizeof(int) * initCapacity);
	new->realSize = 0;
	new->capacity = initCapacity;

	return(new);
}	

void pushInt32(int32Array** target, int item)
{
	int32Array* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = (int*)realloc(targetDerefed->items, sizeof(int) * targetDerefed->capacity);
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;
}

void printInt32Array(int32Array** target)
{
	printf("\n");
	int32Array* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		printf("%d ", targetDerefed->items[idx]);
	}
	printf("\n");
}

void freeInt32Array(int32Array** target)
{
	int32Array* targetDerefed = *target;
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
}

/* End int32Array definition */