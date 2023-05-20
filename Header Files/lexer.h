#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

static const char* KerberosOperations[] = 
{
	"+",
	"="
};

static const char* KerberosKeywords[] = 
{
	"void",

	"u8",
	"u16",
	"u32",
	"u64",

	"i8",
	"i16",
	"i32",
	"i64",

	"f32",
	"f64",

	"char",
	"string",

	"static",
	"const",

	"basis",
	"composition",

	"global",
	"local",
	"shared",

	"if"
	"elif"
	"else",
	"while",
	"for",

	"with",
	"scope",
	"as",
	"continue",
	"break",
	"self",

	"impl",
	"constructor",

	"return"
};

typedef enum KerberosTokenType
{
	operation,
	keyword,
	identifier
} KerberosTokenType;

// 2 bytes of padding
// 24 bytes in total
typedef struct KerberosToken 
{
	unsigned int startPosition;
	unsigned int endPosition;
	KerberosTokenType type;
	char* token;
} Token;

#endif // LEXER_H