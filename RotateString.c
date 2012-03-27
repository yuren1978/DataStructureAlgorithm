#include <stdio.h>


void reverseString(char* test, int length){
	for (int i = 0; i < length/2; i++) {
		char temp=test[i];
		test[i]=test[length-1-i];
		test[length-1-i]=temp;
	}
}

void rotateString(char* test, int offSet){
	int length=strlen(test);
	reverseString(test,offSet);
	reverseString(test+offSet, length-offSet);
	reverseString(test,length);
}


int main(int argc, char* argv[]){
	char test[]="Please rotate me";
	printf("%s\n",test);
	rotateString(test, 3);
	printf("%s\n",test);
}