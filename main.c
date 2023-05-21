#include "Header Files/dArray.h"
#include "Header Files/file.h"
#include "Header Files/lexer.h"
#include "Header Files/parser.h"

int main(void) 
{
	FILE* sourceFile = openFile("../LanguageCode.cb", "r", (long int)NULL);
	char* sourceCode = readAll(sourceFile);

	//Token* tokens = lexify(sourceCode);

	//free(tokens);
	free(sourceCode);
	fclose(sourceFile);

	int32Array* test = initInt32Array(12);
	for(int idx = 1; idx <= 100; idx++)
	{
		pushInt32(&test, idx);
	}
	printInt32Array(&test);
	freeInt32Array(&test);

  	return 0;
}