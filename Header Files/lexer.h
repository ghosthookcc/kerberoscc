#ifndef LEXER_H
#define LEXER_H

#include "file.h"

static const char* KerberosOperations[] = 
{
	"+",
	"*",
	"="
};
static int KerberosOperationsLength = 3;

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
	"enum",

	"global",
	"local",
	"shared",

	"if"
	"elif"
	"else",
	"while",
	"for",
	"continue",
	"break",

	"with",
	"scope",
	"as",
	"self",

	"impl",
	"constructor",

	"unimplemented",
	"return"
};
static int KerberosKeywordsLength = 36;

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

Token* lexify(char* inString);

#endif // LEXER_H