#include <stdio.h>
#include <string.h>

void ReverseString(char* input){
	int length=strlen(input);
	for (int i = 0; i < length/2; i++) {
		char temp=input[i];
		input[i]=input[length-1-i];
		input[length-1-i]=temp;		
	}
}

int main(int argc, char *argv[]) {
	char test[]="I am a test bus";
	printf("%s\n",test);
	ReverseString(test);
	printf("%s\n",test);
}