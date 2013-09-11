#include <stdio.h>

int main(int argc, char *argv[]) {
	char input[]="Hello , Plese remove space from me";
	printf("string length is %d \n", strlen(input));
	char* endPtr=input;
	char* array=input;
	while (*endPtr) {
		if(*endPtr==' '){
			endPtr++;
		}
		else{
			*array++=*endPtr++;
		}
	}
	*array='\0';
	printf("%s \n", input);
	return 0;
}