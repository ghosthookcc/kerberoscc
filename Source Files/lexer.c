#include "../Header Files/lexer.h"

void initKerberosToken(struct KerberosToken* kerbToken)
{
	kerbToken->token = initCharArray(7);
}

charArray* nextToken(char* inString)
{
	charArray* token = initCharArray(7); 

	while (inString[0] != ' '
	&&	   inString[0] != '\n'
	&&     inString[0] != '\0')
	{
		pushChar(&token, inString[0]);
		inString++;
	}
	return(token);
}

struct KerberosToken identifyToken(char* token, 
	                               unsigned int tokenStartOffset,
	                               unsigned int tokenEndOffset)
{
	struct KerberosToken identifiedToken;
	initKerberosToken(&identifiedToken);

	pushChars(&identifiedToken.token, token);
	identifiedToken.startPosition = tokenStartOffset;
	identifiedToken.endPosition   = tokenEndOffset;

	for (int idx = 0; idx < KerberosKeywordsLength; idx++)
	{
		if (compareStrings(token, KerberosKeywords[idx]) == 0)
		{
			identifiedToken.type = keyword;
			return(identifiedToken);
		}
	}
	for (unsigned int idx = 0; idx < KerberosOperationsLength; idx++)
	{
		if (compareStrings(token, KerberosOperations[idx]) == 0)
		{
			identifiedToken.type = operation;
			return(identifiedToken);
		}
	}

	identifiedToken.type = identifier;
	return(identifiedToken);
}

tokenArray* lexify(char* inString)
{
	unsigned int tokenStartOffset = 0;
	unsigned int tokenEndOffset   = 0;

	tokenArray* identifiedTokens = initTokenArray(100);
	
	charArray* token;
	unsigned int tokenLength;

	struct KerberosToken identifiedToken;
	while (1)
	{
		token = nextToken(inString);
		tokenLength = getStringLen(token->items);

		if (inString[0] == '\0')
		{
			break;
		}
		if (token->realSize == 0)
		{ 
			inString++;
			continue;
		}

		inString += tokenLength;
		tokenEndOffset = tokenStartOffset + tokenLength;
		identifiedToken = identifyToken(token->items, 
			                            tokenStartOffset, 
			                            tokenEndOffset);
		pushToken(&identifiedTokens, identifiedToken);
		tokenStartOffset = tokenEndOffset;
	}
	return(identifiedTokens);
}