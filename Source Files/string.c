#include "../Header Files/string.h"

unsigned int getStringLen(char* string)
{
	char* offset = string;
	unsigned int len = 0;
	while (*offset != '\0')
	{
		offset++;
		len++;
	}
	return(len);
}

unsigned char stringEndsWith(char* string, char checkForChar)
{
	unsigned char endsWithChar = 0;
	unsigned int stringLen = getStringLen(string);
	if (string[stringLen-1] == checkForChar)
	{
		endsWithChar = 1;
	}
	return(endsWithChar);
}