#include <stdio.h>
#include <stdbool.h>

bool IsPowerOfIntegerTwo(unsigned int value)
{
	return  (value & (value-1)) ==0;
}



int main(int argc, char *argv[]) {
	printf("%d\n", IsPowerOfIntegerTwo(8));
}