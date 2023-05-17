#include "Header Files/file.h"
#include "Header Files/lexer.h"
#include "Header Files/parser.h"

int main(void) 
{
	FILE* sourceFile = openFile("../LanguageCode.cb", "r", (long int)NULL);

	char* sourceCode = readAll(sourceFile);

	printf(sourceCode);

	free(sourceCode);
	fclose(sourceFile);

  	return 0;
}