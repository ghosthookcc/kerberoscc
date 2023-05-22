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