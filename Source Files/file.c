#include "../Header Files/file.h"

FILE* openFile(char* filePath, const char* fileMode, long int offset)
{
	if (offset == (long int)NULL) offset = 0L;
	FILE* filePtr = fopen(filePath, fileMode);
	fseek(filePtr, offset, SEEK_SET);
	return(filePtr);
}

char readNext(FILE* file)
{
	char next = fgetc(file);
	return(next);
}

char* readNextChars(FILE* file, int amount)
{
	char* content = (char*)malloc( ( sizeof(char) * amount ) + 1);

	int nextCharIdx = 0;
	while (!feof(file) && nextCharIdx < amount)
	{
		content[nextCharIdx] = readNext(file);
		nextCharIdx++; 
	}
	content[nextCharIdx] = '\0';

	return(content);
} 

char* readAll(FILE* file)
{
	long int savedFileOffset = ftell(file);
	rewind(file);
	
	char* content = readRemaining(file);
	fseek(file, savedFileOffset, SEEK_SET);

	return(content);
}

char* readRemaining(FILE* file)
{
	long int contentLength = tellRemaining(file);
	char* content = (char*)malloc( ( sizeof(char) * contentLength ) + 1);

	char nextSymbol;
	int nextSymbolIdx = 0;
	while (!feof(file))
	{
		nextSymbol = readNext(file);
		content[nextSymbolIdx] = nextSymbol;
		nextSymbolIdx++;
	}
	content[nextSymbolIdx] = '\0';

	return(content);
}

long int tellRemaining(FILE* file)
{	
	long int remainingLength = tellSize(file) - ftell(file);
	return(remainingLength);
}

long int tellSize(FILE* file)
{
	long int savedFileOffset = ftell(file);
	fseek(file, 0L, SEEK_END);
	long int size = ftell(file);
	fseek(file, savedFileOffset, SEEK_SET);
	return(size);
}