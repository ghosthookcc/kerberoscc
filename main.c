#include "Header Files/dArray.h"
#include "Header Files/file.h"
#include "Header Files/lexer.h"
#include "Header Files/parser.h"

int main(void) 
{
	FILE* sourceFile = openFile("../LanguageCode.cb", "r", (long int)NULL);
	char* sourceCode = readAll(sourceFile);

	tokenArray* tokens = lexify(sourceCode);
	printTokenArray(&tokens);

	freeTokenArray(&tokens);
	free(sourceCode);
	fclose(sourceFile);

	i32Array* test = initI32Array(12);
	for (int idx = 1; idx <= 100; idx++)
	{
		pushI32(&test, idx);
	}
	printI32Array(&test);
	freeI32Array(&test);

	f32Array* test2 = initF32Array(12);
	for (int idx = 1; idx <= 100; idx++)
	{
		pushF32(&test2, (float)(idx+0.5f));
	}
	printF32Array(&test2);
	freeF32Array(&test2);

	charArray* test3 = initCharArray(12);
	for (int idx = 48; idx <= 122; idx++)
	{
		pushChar(&test3, (char)idx);
	}
	printCharArray(&test3);
	freeCharArray(&test3);

	tokenArray* test5 = initTokenArray(12);
	struct KerberosToken tokenToPush; 
	initKerberosToken(&tokenToPush);
	pushChars(&tokenToPush.token, "asd");

	tokenToPush.type = operation;
	tokenToPush.startPosition = 11;
	tokenToPush.endPosition   = 12;
	pushToken(&test5, tokenToPush);
	printTokenArray(&test5);
	freeTokenArray(&test5);

	stringArray* test4 = initStringArray(12);
	charArray* string = NULL;
	for (int idx = 1; idx <= 10; idx++)
	{
		string = initCharArray(10);
		pushChar(&string, 'm');
		pushChars(&string, "_initValue");
		pushString(&test4, string);
	}
	printStringArray(&test4);
	freeStringArray(&test4);

  	return 0;
}