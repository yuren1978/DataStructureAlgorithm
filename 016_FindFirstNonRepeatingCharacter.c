#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

char FindFirstNonRepeatingCharacter(const char* array, int length){
	int count[SIZE]={0}; //initialize everything to 0.
	for (int i=0; i<length; i++) {
		count[array[i]]++;
	}
	
	for (int i=0; i<SIZE; i++) {
		if(count[i]==1){
			return i;
		}
	}
	return ' ';
}

int main(int argc, char *argv[]) {
	char array[]={'a','b','c','d','e','a','b','g','d','c'};
	int length=sizeof(array)/sizeof(*array);
	char firstNonRepeatingCharacter=FindFirstNonRepeatingCharacter(array, length);	printf("\n First Non Repeating %c", firstNonRepeatingCharacter);
}