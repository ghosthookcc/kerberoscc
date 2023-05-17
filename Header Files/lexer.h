#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

static const char* Operations[] = 
{
	"+",
	"="
};

static const char Keywords[] = 
{
	"i32"
};

typedef enum KerberosTokenType
{
	operation,
	keyword,
	identifier
} KerberosTokenType;

// 2 bytes of padding
typedef struct KerberosToken 
{
	unsigned int startPosition;
	unsigned int endPosition;
	KerberosTokenType type;
	char token[10];
} Token;

#endif // LEXER_H