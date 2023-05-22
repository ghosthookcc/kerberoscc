#ifndef DARRAY_H
#define DARRAY_H

#include <stdlib.h>
#include <stdio.h>

#include "string.h"

/* Start int32Array declaration */

typedef struct i32Array
{
	int* items;
	unsigned int realSize;
	unsigned int capacity;
} i32Array;

i32Array* initI32Array(unsigned int initCapacity);

void pushI32(i32Array** target, int item);

void printI32Array(i32Array** target);

void freeI32Array(i32Array** target);

/* End i32Array declaration */

/* Start f32Array declaration */

typedef struct f32Array
{
	float* items;
	unsigned int realSize;
	unsigned int capacity;
} f32Array;

f32Array* initF32Array(unsigned int initCapacity);

void pushF32(f32Array** target, float item);

void printF32Array(f32Array** target);

void freeF32Array(f32Array** target);

/* End f32Array declaration */

/* Start charArray declaration */

typedef struct charArray
{
	char* items;
	unsigned int realSize;
	unsigned int capacity;
} charArray;

charArray* initCharArray(unsigned int initCapacity);

void pushChar(charArray** target, char item);

void pushChars(charArray** target, char* item);

void printCharArray(charArray** target);

void freeCharArray(charArray** target);

/* End charArray declaration */

/* Start stringArray declaration */

typedef struct stringArray
{
	charArray** items;
	unsigned int realSize;
	unsigned int capacity;
} stringArray;

stringArray* initStringArray(unsigned int initCapacity);

void pushString(stringArray** target, charArray* item);

void printStringArray(stringArray** target);

void freeStringArray(stringArray** target);

/* End stringArray declaration */

/* Start tokenArray declaration */

#include "lexer.h"

typedef struct tokenArray
{
	struct KerberosToken* items;
	unsigned int realSize;
	unsigned int capacity;
} tokenArray;

tokenArray* initTokenArray(unsigned int initCapacity);

void pushToken(tokenArray** target, struct KerberosToken item);

void printTokenArray(tokenArray** target);

void freeTokenArray(tokenArray** target);

/* End tokenArray declaration */

#endif // DARRAY_H