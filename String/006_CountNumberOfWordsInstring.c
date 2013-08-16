#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {false, true} bool;

int CountNumberOfWordsInString(const char* sentence)
{
	
}

int main(int argc, char *argv[]) {
	const char* test=" I am just a test";
	printf("word count : %d\n",CountNumberOfWordsInString(test) );
	assert(5==CountNumberOfWordsInString(test));
	printf("%s\n", test);	
}