#include "../Header Files/lexer.h"

charArray* nextToken(char* inString)
{
	charArray* token = initCharArray(6); 
	while (inString[0] != ' ')
	{
		if (inString[0] == '\0')
		{
			pushChar(&token, '\0');
			break;
		}
		pushChar(&token, inString[0]);
		inString++;
	}
	return(token);
}

struct KerberosToken* identifyToken(char* token)
{

}

void lexify(char* inString)
{
	char* stringOffset = inString;
	charArray* token;
	do
	{
		token = nextToken(stringOffset);
		for (unsigned int idx = 0; idx < getStringLen(token->items)+1; idx++)
		{
			stringOffset++;
		}
	} while (stringEndsWith(token->items, '\0') != 1);
}