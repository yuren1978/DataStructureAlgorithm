#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {false, true} bool;

int CountNumberOfWordsInString(const char* sentence){
	int count=0;
	bool word=false;
	char* p=sentence;
	while (*p !='\0') {
		//printf("%c \t", *p);
		if(*p !=' '&& !word){
			//printf(" word count ");
			++count;
			word=true;
		}
		else {
			if(*p ==' '&& word){
				word=false;
			}
		}
		p++;
	}
	return count;
}

int main(int argc, char *argv[]) {
	const char* test=" I am just a test";
	printf("word count : %d\n",CountNumberOfWordsInString(test) );
	assert(5==CountNumberOfWordsInString(test));
	printf("%s\n", test);	
}