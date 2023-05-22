#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "dArray.h"
#include "string.h"

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
static int KerberosKeywordsLength = 34;

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
	charArray* token;
	KerberosTokenType type;
	unsigned int startPosition;
	unsigned int endPosition;
} KerberosToken;

void initKerberosToken(struct KerberosToken* kerbToken);

charArray* nextToken(char* inString);

struct KerberosToken identifyToken(char* token,
	                               unsigned int tokenStartOffset,
	                               unsigned int tokenEndOffset);

struct tokenArray* lexify(char* inString);

#endif // LEXER_H