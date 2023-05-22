#include "../Header Files/dArray.h"

/* Start i32Array definition */

i32Array* initI32Array(unsigned int initCapacity)
{
	i32Array* new = malloc(sizeof(i32Array*) + (sizeof(int) * initCapacity));
	
	new->items = malloc(sizeof(int) * initCapacity);
	new->realSize = 0;
	new->capacity = initCapacity;

	return(new);
}	

void pushI32(i32Array** target, int item)
{
	i32Array* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = realloc(targetDerefed->items, sizeof(int) * targetDerefed->capacity);
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;
}

void printI32Array(i32Array** target)
{
	printf("\n");
	i32Array* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		printf("%d ", targetDerefed->items[idx]);
	}
	printf("\n");
}

void freeI32Array(i32Array** target)
{
	i32Array* targetDerefed = *target;
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
	free(targetDerefed);
}

/* End i32Array definition */

/* Start f32Array definition */

f32Array* initF32Array(unsigned int initCapacity)
{
	f32Array* new = malloc(sizeof(f32Array*) + (sizeof(float) * initCapacity));
	
	new->items = malloc(sizeof(float) * initCapacity);
	new->realSize = 0;
	new->capacity = initCapacity;

	return(new);
}	

void pushF32(f32Array** target, float item)
{
	f32Array* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = realloc(targetDerefed->items, sizeof(float) * targetDerefed->capacity);
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;
}

void printF32Array(f32Array** target)
{
	printf("\n");
	f32Array* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		printf("%f ", targetDerefed->items[idx]);
	}
	printf("\n");
}

void freeF32Array(f32Array** target)
{
	f32Array* targetDerefed = *target;
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
	free(targetDerefed);
}

/* End f32Array definition */

/* Start charArray definition */

charArray* initCharArray(unsigned int initCapacity)
{
	charArray* new = malloc(sizeof(charArray*) + (sizeof(char) * initCapacity));
	
	new->items = malloc((sizeof(char) * initCapacity) + 1);
	new->realSize = 0;
	new->capacity = initCapacity;

	new->items[new->realSize] = '\0';

	return(new);
}		

void pushChar(charArray** target, char item)
{
	charArray* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = realloc(targetDerefed->items, (sizeof(char) * targetDerefed->capacity) + 1);
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;			
	targetDerefed->items[targetDerefed->realSize] = '\0';
}

void pushChars(charArray** target, char* item)
{
	charArray* targetDerefed = *target;
	unsigned int itemCharsLen = sizeof(char) * getStringLen(item);
	if (targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = itemCharsLen + (targetDerefed->capacity * 2) + 1;
		targetDerefed->items = realloc(targetDerefed->items, sizeof(char) * targetDerefed->capacity);
	}
	for (unsigned int idx = 0; idx < itemCharsLen; idx++)
	{
		targetDerefed->items[targetDerefed->realSize] = (char)item[idx];
		targetDerefed->realSize++;
	}
	targetDerefed->items[targetDerefed->realSize] = '\0';
}

void printCharArray(charArray** target)
{
	printf("\n");
	charArray* targetDerefed = *target;
	printf("%s ", targetDerefed->items);
	printf("\n");
}

void freeCharArray(charArray** target)
{
	charArray* targetDerefed = *target;
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
	free(targetDerefed);
}

/* End charArray definition */

/* Start stringArray definition */

stringArray* initStringArray(unsigned int initCapacity)
{
	stringArray* new = malloc(sizeof(stringArray*) + (sizeof(charArray*) * initCapacity));

	new->items = malloc(sizeof(charArray*) * initCapacity);
	new->realSize = 0;
	new->capacity = initCapacity;

	return(new);
}

void pushString(stringArray** target, charArray* item)
{
	stringArray* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = realloc(targetDerefed->items, sizeof(charArray*) * targetDerefed->capacity);	
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;
}

void printStringArray(stringArray** target)
{
	printf("\n");
	stringArray* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		printCharArray(&targetDerefed->items[idx]);
	}
	printf("\n");
}

void freeStringArray(stringArray** target)
{
	stringArray* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		freeCharArray(&targetDerefed->items[idx]);
	}
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
	free(targetDerefed);
}

/* End stringArray definition */

/* Start tokenArray definition */

tokenArray* initTokenArray(unsigned int initCapacity)
{
	tokenArray* new = malloc(sizeof(tokenArray*) + sizeof(KerberosToken) * initCapacity);
	new->items = malloc(sizeof(KerberosToken) * initCapacity);
	new->realSize = 0;
	new->capacity = initCapacity;
	return(new);
}

void pushToken(tokenArray** target, struct KerberosToken item)
{
	tokenArray* targetDerefed = *target;
	if ( targetDerefed->realSize == targetDerefed->capacity )
	{
		// Grow target array by 2k+1
		targetDerefed->capacity = targetDerefed->capacity * 2 + 1;
		targetDerefed->items = realloc(targetDerefed->items, sizeof(KerberosToken*) * targetDerefed->capacity);
	}
	targetDerefed->items[targetDerefed->realSize] = item;
	targetDerefed->realSize++;
}

void printTokenArray(tokenArray** target)
{
	printf("\n");
	tokenArray* targetDerefed = *target;
	for (unsigned int idx = 0; idx < targetDerefed->realSize; idx++)
	{
		printf("Token[%s]\n"
			   "Type[%d]\n"
			   "StartPos[%d]\n"
			   "EndPos[%d]\n\n", 
			    targetDerefed->items[idx].token->items,
			    targetDerefed->items[idx].type,
			    targetDerefed->items[idx].startPosition,
			    targetDerefed->items[idx].endPosition);
	}
	printf("\n");	
}

void freeTokenArray(tokenArray** target)
{
	tokenArray* targetDerefed = *target;
	free(targetDerefed->items);
	targetDerefed->items = NULL;
	targetDerefed->realSize = targetDerefed->capacity = 0;
	free(targetDerefed);
}

/* End tokenArray definition */